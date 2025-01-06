#ifndef RANGE_HPP
#define RANGE_HPP

#include "config.hpp"

class range {
  public:

  double min, max;

  range() : min(-INF), max(INF) {}
  range(double min, double max) : min(min), max(max) {}

  double width() const {
    return max - min;
  }

  bool contains(double x) const {
    return min <= x && x <= max;
  } 

  bool contains_non_inclusive(double x) const {
    return min < x && x < max;
  }

  static const range empty, all;
};

const range range::empty = range(+INF, -INF);
const range range::all = range(-INF, +INF);

#endif