#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include "vec3.hpp"

using namespace std;
typedef vec3 color;

void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  unsigned char r_num = clamp(255.999 * r, 0.0, 255.0);
  unsigned char g_num = clamp(255.999 * g, 0.0, 255.0);
  unsigned char b_num = clamp(255.999 * b, 0.0, 255.0);

  out << r_num << g_num << b_num;
}

#endif