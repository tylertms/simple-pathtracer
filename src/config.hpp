#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <cmath>
#include <iostream>
#include <fstream>
#include <limits>
#include <memory>

using std::make_shared;
using std::shared_ptr;

#include "color.hpp"
#include "ray.hpp"
#include "vec3.hpp"

#define FILE_NAME_LENGTH 32

#define IMG_WIDTH 1024
#define IMG_HEIGHT 1024

constexpr double INF = std::numeric_limits<double>::infinity();
constexpr double PI = M_PI;

inline double deg_to_rad(double degrees) {
    return degrees * PI / 180.0;
}

inline double rad_to_deg(double rad) {
  return rad * 180.0 / PI;
}

#endif