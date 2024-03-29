#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

#include "color.h"
#include "hittable.h"
#include "material.h"
#include <vector>

#include <iostream>
#include <Windows.h>

class camera;

typedef struct
{
    long    tileID;
    HANDLE  barrier;
    std::vector<color>* framebuffer;
    int iw;
    int ih;
    const hittable& world;
    camera* cam;
}TData;


class camera {
public:
    /* Public Camera Parameters Here */
    double      aspect_ratio = 1.0;  // Ratio of image width over height
    int          image_width = 100;  // Rendered image width in pixel count
    int     samples_per_pixel = 10;  // Count of random samples for each pixel
    int             max_depth = 10;  // Maximum number of ray bounces into scene
    color   background;              // Scene background color

    double vfov = 90;  // Vertical view angle (field of view)
    point3 lookfrom = point3(0, 0, -1);  // Point camera is looking from
    point3 lookat = point3(0, 0, 0);   // Point camera is looking at
    vec3   vup = vec3(0, 1, 0);     // Camera-relative "up" direction

    double defocus_angle = 0; // Variation angle of rays through each pixel
    double focus_dist = 10;     // Distance from camera lookfrom pint to plane of perfect focus
    friend DWORD WINAPI doRender(void* vdata);
    static DWORD WINAPI doRender(void* vdata);

    //-----------------------------------------------------
    // render image
    //-----------------------------------------------------
    void renderImage(const hittable& world)
    {
        initialize();
        // get number of CPUs available
        SYSTEM_INFO si;
        GetSystemInfo(&si);
        const int numCpus = min(si.dwNumberOfProcessors, 256);
        std::vector<color> framebuffer(image_width * image_height);

        // data for worker threads
        __declspec(align(32)) TData data = {
            0,                                         // tile id/counter
            CreateSemaphore(0, numCpus, numCpus, 0), // create barrier
            &framebuffer, image_width, image_height, world, this           // image
        };

        // launch worker threads
        HANDLE th[256];
        for (int i = 0; i < numCpus; i++)
            th[i] = CreateThread(0, 0, doRender, &data, 0, 0);

        // wait for worker threads to finish
        WaitForMultipleObjects(numCpus, th, true, INFINITE);

        // destroy threads
        for (int i = 0; i < numCpus; i++)
            CloseHandle(th[i]);

        // destroy barrier
        CloseHandle(data.barrier);

        // Output the framebuffer
        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
        for (int j = 0; j < image_height; ++j) {
            for (int i = 0; i < image_width; ++i) {
                write_color(std::cout, framebuffer[j * image_width + i], samples_per_pixel);
            }
        }

        std::clog << "\rDone.\n";
    }

    void render(const hittable& world) {
        initialize();

        const int tilesize = 16;
        const int numxtiles = image_width / tilesize;
        const int numytiles = image_height / tilesize;

        std::vector<color> framebuffer(image_width * image_height);

        // Render tiles
        for (int tile = 0; tile < numxtiles * numytiles; ++tile) {
            // Tile offset
            int ia = tilesize * (tile % numxtiles);
            int ja = tilesize * (tile / numxtiles);

            // For every pixel in this tile, compute color
            for (int j = 0; j < tilesize; ++j) {
                for (int i = 0; i < tilesize; ++i) {
                    int x = ia + i;
                    int y = ja + j;
                    if (x >= image_width || y >= image_height) continue; // Skip pixels outside the image bounds
                    color pixel_color = compute_color(x, y, world);
                    framebuffer[y * image_width + x] = pixel_color;
                }
            }
        }

        // Output the framebuffer
        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
        for (int j = 0; j < image_height; ++j) {
            for (int i = 0; i < image_width; ++i) {
                write_color(std::cout, framebuffer[j * image_width + i], samples_per_pixel);
            }
        }

        std::clog << "\rDone.\n";
    }

    color compute_color(int i, int j, const hittable& world) {
        color pixel_color(0, 0, 0);
        for (int s = 0; s < samples_per_pixel; ++s) {
            ray r = get_ray(i, j);
            pixel_color += ray_color(r, max_depth, world);
        }
        return pixel_color;
    }

private:
    int    image_height = 0;   // Rendered image height
    point3 center;         // Camera center
    point3 pixel00_loc;    // Location of pixel 0, 0
    vec3   pixel_delta_u;  // Offset to pixel to the right
    vec3   pixel_delta_v;  // Offset to pixel below
    vec3   u, v, w;        // Camera frame basis vectors
    vec3   defocus_disk_u;  // Defocus disk horizontal radius
    vec3   defocus_disk_v;  // Defocus disk vertical radius

    void initialize() {
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        center = lookfrom;

        // Determine viewport dimensions.

        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta / 2);
        auto viewport_height = 2 * h * focus_dist;
        auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

        // Calculate the u,v,w unit basis vectors for the camera coordinate frame.
        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(vup, w));
        v = cross(w, u);

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        vec3 viewport_u = viewport_width * u;    // Vector across viewport horizontal edge
        vec3 viewport_v = viewport_height * -v;  // Vector down viewport vertical edge

        // Calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Calculate the location of the upper left pixel.
        auto viewport_upper_left = center - (focus_dist * w) - viewport_u / 2 - viewport_v / 2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

        // Calculate the camera defocus disk basis vectors.
        auto defocus_radius = focus_dist * tan(degrees_to_radians(defocus_angle / 2));
        defocus_disk_u = u * defocus_radius;
        defocus_disk_v = v * defocus_radius;
    }

    ray get_ray(int i, int j) const {
        // Get a randomly-sampled camera ray for the pixel at location i,j, originating from
        // the camera defocus disk.

        auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
        auto pixel_sample = pixel_center + pixel_sample_square();

        auto ray_origin = (defocus_angle <= 0) ? center : defocus_disk_sample();
        auto ray_direction = pixel_sample - ray_origin;
        auto ray_time = random_double();

        return ray(ray_origin, ray_direction, ray_time);

    }

    vec3 pixel_sample_square() const {
        // Returns a random point in the square surrounding a pixel at the origin.
        auto px = -0.5 + random_double();
        auto py = -0.5 + random_double();
        return (px * pixel_delta_u) + (py * pixel_delta_v);
    }

    point3 defocus_disk_sample() const {
        // Returns a random point in the camera defocus disk.
        auto p = random_in_unit_disk();
        return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
    }

    color ray_color(const ray& r, int depth, const hittable& world) const {
        hit_record rec;

        // If we've exceeded the ray bounce limit, no more light is gathered.
        if (depth <= 0)
            return color(0, 0, 0);

        // If the ray hits nothing, return the background color.
        if (!world.hit(r, interval(0.001, infinity), rec))
            return background;

        ray scattered;
        color attenuation;
        color color_from_emission = rec.mat->emitted(rec.u, rec.v, rec.p);

        if (!rec.mat->scatter(r, rec, attenuation, scattered))
            return color_from_emission;

        color color_from_scatter = attenuation * ray_color(scattered, depth - 1, world);

        return color_from_emission + color_from_scatter;
    }
};

DWORD WINAPI camera::doRender(void* vdata)
{
#define TILESIZE 16

    // prep data
    TData* data = (TData*)vdata;
    const int width = data->iw;
    const int height = data->ih;

    const int   numxtiles = width / TILESIZE;
    const int   numytiles = height / TILESIZE;
    const int   numtiles = numxtiles * numytiles;
    //const hittable& world = data->world;

    // synch point
    WaitForSingleObject(data->barrier, 0);

    // render tiles
    for (;;)
    {
        // get next tile to consume
        const int tile = InterlockedIncrement(&data->tileID) - 1;
        if (tile >= numtiles) break;

        // tile offset
        const int ia = TILESIZE * (tile % numxtiles);
        const int ja = TILESIZE * (tile / numxtiles);

        // for every pixel in this tile, compute color
        for (int j = 0; j < TILESIZE; j++)
            for (int i = 0; i < TILESIZE; i++)
                data->framebuffer->at(width * (ja + j) + (ia + i)) = data->cam->compute_color(
                    ia + i, ja + j, data->world);
    }

    // synch point
    ReleaseSemaphore(data->barrier, 1, NULL);

    return 1;
}

#endif