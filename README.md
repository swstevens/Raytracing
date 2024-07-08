# C++ Raytracing

A personal learning project about ray tracing using C++. Follows the wonderful guide found here:
[https://raytracing.github.io/books/RayTracingInOneWeekend.html](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

After finishing the project's instructions, I've gone ahead working on rendering tris. They are functional and can be seen in triangle.h. Implementations to add include texture mapping and vertex lighting.

The final goal is to be able to render ps1 video game models using this script.

## Deployment

To deploy this project run

```bash
  cd build
  cmake ..
  make
  ./raytracing > [out_file.ppm]
