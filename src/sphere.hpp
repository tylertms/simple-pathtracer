#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "object.hpp"

class sphere : public object {
 private:
  vec3 center;
  double radius;

 public:
  sphere(const point3& center, double radius)
      : center(center), radius(radius) {}

  bool intersection(const ray& r, range t_limit, hit& h) const override {
    vec3 offset = center - r.origin();

    // simplified quadratic formula
    double a = r.direction().length_squared();
    double b = dot(r.direction(), offset);
    double c = offset.length_squared() - radius * radius;

    double discriminant = b * b - a * c;

    if (discriminant < 0) {
      return false;
    }

    double sd = sqrt(discriminant);
    double root = (b - sd) / a;
    if (!t_limit.contains_exclusive(root)) {
      root = (b + sd) / a;
      if (!t_limit.contains_exclusive(root))
        return false;
    }

    h.time = root;
    h.point = r.at(root);
    vec3 outward_normal = (h.point - center) / radius;
    h.set_face_normal(r, outward_normal);

    return true;
  }
};

#endif