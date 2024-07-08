#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.h"
#include "vec3.h"

class triangle : public hittable {
  public:
        triangle(const point3& point_a, const point3& point_b, const point3& point_c, shared_ptr<material> mat)
      : point_a(point_a), point_b(point_b), point_c(point_c), mat(mat) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
      const float EPSILON = 0.0000001f;
      vec3 edge1 = point_b - point_a;
      vec3 edge2 = point_c - point_a;
      vec3 h = cross(r.direction(), edge2);
      float a = dot(edge1, h);

      if (a > -EPSILON && a < EPSILON) {
          return false; // Ray is parallel to the triangle
      }

      float f = 1.0f / a;
      vec3 s = r.origin() - point_a;
      float u = f * dot(s, h);

      if (u < 0.0f || u > 1.0f) {
          return false;
      }

      vec3 q = cross(s, edge1);
      float v = f * dot(r.direction(), q);

      if (v < 0.0f || u + v > 1.0f) {
          return false;
      }

      const float t = f * dot(edge2, q);

      if (t < EPSILON) {
        return false;
      }

<<<<<<< HEAD
      rec.t = 0.5;
=======
      auto root = t;
        if (!ray_t.surrounds(root)) {
            root = -t;
            if (!ray_t.surrounds(root))
                return false;
        }

      // find the angle between down (0,-1,0) and the plane. if cos(theta) is less than 0 then render some shadow based on that value.
      rec.t = root;
>>>>>>> 95d71d18bab549753cbde7f2587f6920e2dec3d2
      rec.p = r.at(rec.t);
      vec3 outward_normal = unit_vector(cross(edge1, edge2));
      rec.set_face_normal(r, outward_normal);
      rec.mat = mat;
      return true;  
    }

  private:
    point3 point_a;
    point3 point_b;
    point3 point_c;
    shared_ptr<material> mat;
};

#endif