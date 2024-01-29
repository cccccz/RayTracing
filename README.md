# Ray Tracing Exploration

Exploring the concepts of Ray Tracing following the book [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html).

## Diffuse Objects

Rendering of diffuse objects showing the effect of a basic diffuse shading model.

![Diffuse Object](https://github.com/cccccz/RayTracing/assets/60713799/810ed421-e56e-4cf7-a450-023d464bb5f4)
![Diffuse Object - Second View](https://github.com/cccccz/RayTracing/assets/60713799/6d60132d-b487-4ce1-9b81-71a717fbf4a1)

## After Gamma Correction with Lambertian Model

Improved realism with gamma correction applied to the diffuse Lambertian reflection model.

![After Gamma Correction, Lambertian Model](https://github.com/cccccz/RayTracing/assets/60713799/0e066cee-733b-4d1f-bb55-30adacdbeb64)

## Metal Materials

Demonstration of metallic surfaces with reflections.

![Metal](https://github.com/cccccz/RayTracing/assets/60713799/8399f9fd-a732-41df-9692-3afb47c0bb0f)

### Metal with Fuzzy Effect

Metal surfaces with a simple fuzzy effect to simulate surface roughness.

![Metal with Simple Fuzzy Effect](https://github.com/cccccz/RayTracing/assets/60713799/a9813bb8-6af2-436f-8a2c-b7ce318615dd)

## Glass with Refraction

Visualizing refraction through a glass material.

![Glass with Refraction](https://github.com/cccccz/RayTracing/assets/60713799/846f3ea9-7d67-4b30-a3e5-ee32c8475169)

### Hollow Glass Sphere with Negative Radius

A hollow glass sphere using a negative radius to illustrate the effect of inverted normals.

![Hollow Glass Sphere with Negative Radius](https://github.com/cccccz/RayTracing/assets/60713799/31e345f5-07db-4525-b92c-0d68b18cf794)

## Field of View (FOV) Comparison

Comparison of scenes rendered with different FOV settings. The FOV can significantly alter the perspective of the scene.

![FOV 90](https://github.com/cccccz/RayTracing/assets/60713799/33e19237-8136-414f-a505-6d337860553a)
![FOV 120](https://github.com/cccccz/RayTracing/assets/60713799/42bcc0ff-c2c7-4260-b657-999880e632c1)

## Camera Positioning

The position of the camera can drastically change the composition and feel of the rendered scene.

![Camera Positioning](https://github.com/cccccz/RayTracing/assets/60713799/a6a2d3ba-3163-4028-9b10-4ff3055c41f1)

### Narrow FOV (FOV 20)

A narrow field of view can focus the attention on a specific part of the scene.

![FOV 20](https://github.com/cccccz/RayTracing/assets/60713799/223d6d7a-01b8-4ca3-acef-813443df0f17)

## Depth of Field

Adjusting the depth of field through different angles to simulate camera lens effects.

### Depth of Field Angle = 10

![Depth of Field Angle 10](https://github.com/cccccz/RayTracing/assets/60713799/261918e1-0b6f-4dee-bbed-954402fde4e2)

### Depth of Field Angle = 40

![Depth of Field Angle 40](https://github.com/cccccz/RayTracing/assets/60713799/396d5926-c789-41c4-ba2f-11663b1b3d39)

## Final Scene Rendering

The final scene was complex and rendering times were significant with the initial code. To manage this, I employed multi-threaded CPU rendering. Here are the results:

### First Attempt with Multithreading

The first attempt led to a race condition, causing the rendered image to be incorrect.

![First Attempt](https://github.com/cccccz/RayTracing/assets/60713799/10231e97-4f32-4637-a94d-21b5314e54c0)

### Second Attempt with Multithreading:
![Final Result](https://github.com/cccccz/RayTracing/assets/60713799/f0f4196d-32ed-4f07-b64c-e94622ff36bf)

### To Be Continued
It's been a fun weekend journey to me and I think I want to explore more.












