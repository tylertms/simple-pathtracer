#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

class ray {
  private:
    point3 org;
    vec3 dir;

  public:
    ray() {}
    ray(const point3& org, const vec3& dir) : org(org), dir(dir) {}

    const point3& direction() const { return dir; }
    const vec3& origin() const { return org; }


    point3 at(double t) const {
      return org + dir * t;
    }
};

#endif