#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>
#include <memory>

using std::make_shared;
using std::shared_ptr;

#define FILE_NAME_LENGTH 32

const double infinity = std::numeric_limits<double>::infinity();
const double PI = M_PI;

inline double deg_to_rad(double degrees) {
    return degrees * PI / 180.0;
}

inline double rad_to_deg(double rad) {
  return rad * 180.0 / PI;
}

#include "vec3.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "range.hpp"

#endif