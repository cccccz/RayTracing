# Ray Tracing Exploration

Exploring the concepts of Ray Tracing following the book [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html).[_Ray Tracing: The Next Week](https://raytracing.github.io/books/RayTracingTheNextWeek.html).

## Newest Image
![sweetdream](https://github.com/cccccz/RayTracing/assets/60713799/086e78f0-4979-4a4f-8d86-5ce66bd550ef)


# RayTracing Adventure Log
The rest of this README is the log of me following along the books listed above.

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

## To Be Continued
It's been a fun weekend journey to me and I think I want to explore more(2024-01-28).

## The Next Week
Exploring the concepts of Ray Tracing following the book [_Ray Tracing: The Next Week_](https://raytracing.github.io/books/RayTracingTheNextWeek.html).

## Space Time Ray Tracing and Motion Blur
![image](https://github.com/cccccz/RayTracing/assets/60713799/e1aec6fb-e39b-4d09-acb3-4803af841d76)

## Bounding Volume Hierachies with Axis-Aligned Bounding Boxes
With BVH and multithreading, this is much faster comparing to the time I spent yesterday.
Time to sleep, good night(2024-01-30 02:30 a.m). 
![image](https://github.com/cccccz/RayTracing/assets/60713799/b4a72881-2b5f-4e3e-88ee-32d40353210f)

## Texture Mapping(Lambertian, Solid)
mapped the checked texture to the ground
![image](https://github.com/cccccz/RayTracing/assets/60713799/fd5ffc3b-f286-473e-8b88-0c95101304fc)

### Texture Mapping(Sphereical)
#### Mapped the earchmap to a sphere
![image](https://github.com/cccccz/RayTracing/assets/60713799/fdbcc579-b81c-4da5-a195-64017617c723)
![image](https://github.com/cccccz/RayTracing/assets/60713799/ea703a49-0473-4fed-8bfe-7754b0f8327f)
#### From a different angle
![image](https://github.com/cccccz/RayTracing/assets/60713799/7903ec6e-b638-4a7c-a3af-b89998de780e)

### Perlin Noise
#### A repeatable fake random pattern hack invented by Ken Perlin.
![image](https://github.com/cccccz/RayTracing/assets/60713799/8238bf7a-693c-4c91-b7d1-214aa7a1dd91)

#### Smoothing using trilinear interpolation using lattice points on the unit cube(of the noise space?)
![image](https://github.com/cccccz/RayTracing/assets/60713799/47182fbf-99fa-4b10-bbc0-54458b48b2da)

#### Hermitian smoothing
![image](https://github.com/cccccz/RayTracing/assets/60713799/97a653db-fe30-48f4-acb3-f7b431ce91dd)

#### Artifacts of Perlin after smoothing
Blocky artifacts because max and min fall on integer values
![image](https://github.com/cccccz/RayTracing/assets/60713799/64afb7e7-741a-446c-908e-abd051159552)

Trick of using dot product to move max and min off lattice points
![image](https://github.com/cccccz/RayTracing/assets/60713799/ae4f1464-563e-4cc6-afec-adc3b2887f33)

#### Turbulence created by multiple summed frequencies, camouflage effect

![image](https://github.com/cccccz/RayTracing/assets/60713799/9540245a-3687-45e6-a684-13f17eda0ae4)

#### Making colour proportional to a sin function with the turbulence adjusting the phase

![image](https://github.com/cccccz/RayTracing/assets/60713799/2d1433d2-c490-4e0f-bd80-eeac6375c4a5)
(2024-02-02 7:24 am)

## Color Mixing

### 1
![image](https://github.com/cccccz/RayTracing/assets/60713799/b91bd6d0-9b54-4d93-a342-f1e4ab756fb2)
### 2
![image](https://github.com/cccccz/RayTracing/assets/60713799/d34543fb-8032-4482-8532-3f4967211c11)
### 3
![image](https://github.com/cccccz/RayTracing/assets/60713799/3c85daa5-415d-4aef-ae3d-8f47a3907b64)
### 4
![image](https://github.com/cccccz/RayTracing/assets/60713799/4b4d5b7b-86de-4000-afe8-be8603382d6c)

## Noise with different frequencies and magnitudes
![image](https://github.com/cccccz/RayTracing/assets/60713799/ac8e56a0-3954-4313-ab28-f6868ac59a38)
![image](https://github.com/cccccz/RayTracing/assets/60713799/15aaade3-2e10-4042-911b-bb1edea7148f)

### Colors get too dark when addition is not normalized(by 255)
![image](https://github.com/cccccz/RayTracing/assets/60713799/1fc6120a-95b1-4ae6-aac5-bb03b6417a89)

## Mapped my cat to a sphere, she is so cute T^T
![image](https://github.com/cccccz/RayTracing/assets/60713799/d3b71687-d2e8-44da-8e45-b6b254768917)

## Introduced Quads(Quadrilaterals... I think I spelled it right)
![image](https://github.com/cccccz/RayTracing/assets/60713799/4f39f0e0-9a2c-4cbc-bd43-759f383022e3)

### Diffuse Light
![image](https://github.com/cccccz/RayTracing/assets/60713799/94684208-6ad8-42ab-ac2c-a881ea4e1eba)
#### I didn't know that we could turn normal object to lights by making them "emissive". It was a neat trick.
![image](https://github.com/cccccz/RayTracing/assets/60713799/a0044a43-ef1f-4e4b-9c6a-7f69082b8af5)

#### And Yes Light can have color preferences
![image](https://github.com/cccccz/RayTracing/assets/60713799/d44ec6be-718a-4200-87ea-6f6923b9a8a2)

## Cornell Box
### My first Cornell Box
![image](https://github.com/cccccz/RayTracing/assets/60713799/32b112a5-9c2e-4207-b48e-d9d9589fb307)

### The book says the scene is noisy because the light source is too small so I tried a bigger one
![image](https://github.com/cccccz/RayTracing/assets/60713799/333d3547-ad23-475c-80ad-5c07ca092369)

### Cornell Box Illuminated by a super red light source
![image](https://github.com/cccccz/RayTracing/assets/60713799/03f510a4-41b7-4909-a235-26e35d409abf)

![image](https://github.com/cccccz/RayTracing/assets/60713799/57c334a7-1755-4865-8f6f-cee384e7e445)

![image](https://github.com/cccccz/RayTracing/assets/60713799/18ba6581-d0b5-4300-b213-396f47dc824b)

![image](https://github.com/cccccz/RayTracing/assets/60713799/505fd71e-cc53-4a75-9036-2620364573f7)

![image](https://github.com/cccccz/RayTracing/assets/60713799/cf1aab6a-8b3d-4406-a4b4-87baaa14548f)

## Sweet Dream
![sweetdream](https://github.com/cccccz/RayTracing/assets/60713799/086e78f0-4979-4a4f-8d86-5ce66bd550ef)
It took more than 40 mins to render this sweet dream image(using CPU parallelism)
The perlin texture is not the same, the issue has been there since the perlin noise chapter.





























