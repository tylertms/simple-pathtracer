#ifndef RANGE_HPP
#define RANGE_HPP

#include "config.hpp"

class range {
 public:
  double min, max;

  range() : min(-infinity), max(infinity) {}
  range(double min, double max) : min(min), max(max) {}

  double width() const { return max - min; }

  bool contains(double x) const { return min <= x && x <= max; }

  bool contains_exclusive(double x) const { return min < x && x < max; }

  static const range empty, all;
};

const range range::empty = range(+infinity, -infinity);
const range range::all = range(-infinity, +infinity);

#endif