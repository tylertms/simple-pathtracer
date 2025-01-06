#ifndef COLOR_HPP
#define COLOR_HPP

#include "vec3.hpp"

#include <iostream>
typedef vec3 color;

void write_color(std::ostream& out, const color& pixel_color) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  unsigned char r_num = 255.999 * r;
  unsigned char g_num = 255.999 * g;
  unsigned char b_num = 255.999 * b;

  out << r_num << g_num << b_num;
}

#endif