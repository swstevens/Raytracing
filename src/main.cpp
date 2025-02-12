#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "triangle.h"
#include "camera.h"
#include "material.h"


int main() {
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    auto material1 = make_shared<lambertian>(color(1, 0, 0));
    auto material2 = make_shared<lambertian>(color(0, 1, 0));
    auto material3 = make_shared<lambertian>(color(0, 0, 1));
    auto material4 = make_shared<lambertian>(color(1, 1, 1));
    world.add(make_shared<triangle>(point3(0, 2, 0), point3(2, 1, 1), point3(0, 1, 2), material1));
    world.add(make_shared<triangle>(point3(0, 2, 0), point3(2, 1, 1), point3(3, 1, 2), material2));
    world.add(make_shared<triangle>(point3(0, 2, 0), point3(0, 1, 2), point3(3, 1, 2), material3));
    world.add(make_shared<triangle>(point3(0, 1, 2), point3(2, 1, 1), point3(3, 1, 2), material4));

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 640;
    cam.samples_per_pixel = 25;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.lookfrom = point3(13,2,3);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}