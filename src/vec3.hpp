#ifndef VEC3_HPP
#define VEC3_HPP

#include <math.h>

class vec3 {
 public:
  double n[3];

  vec3() : n{0, 0, 0} {};
  vec3(double x, double y, double z) : n{x, y, z} {}

  double x() const { return n[0]; }
  double y() const { return n[1]; }
  double z() const { return n[2]; }

  vec3 operator-() const { return vec3(-n[0], -n[1], -n[2]); }
  double operator[](int i) const { return n[i]; }
  double& operator[](int i) { return n[i]; }

  vec3& operator+=(const vec3& v) {
    n[0] += v.n[0];
    n[1] += v.n[1];
    n[2] += v.n[2];
    return *this;
  }

  vec3& operator-=(const vec3& v) { return *this += -v; }

  vec3& operator*=(const vec3& v) {
    n[0] *= v.n[0];
    n[1] *= v.n[1];
    n[2] *= v.n[2];
    return *this;
  }

  vec3& operator*=(double t) {
    n[0] *= t;
    n[1] *= t;
    n[2] *= t;
    return *this;
  }

  vec3& operator/=(double t) { return *this *= 1 / t; }

  double length_squared() const {
    return n[0] * n[0] + n[1] * n[1] + n[2] * n[2];
  }

  double length() const { return sqrt(length_squared()); }
};

typedef vec3 point3;

inline vec3 operator+(const vec3& a, const vec3& b) {
  return vec3(a.n[0] + b.n[0], a.n[1] + b.n[1], a.n[2] + b.n[2]);
}

inline vec3 operator-(const vec3& a, const vec3& b) {
  return vec3(a.n[0] - b.n[0], a.n[1] - b.n[1], a.n[2] - b.n[2]);
}

inline vec3 operator*(const vec3& a, const vec3& b) {
  return vec3(a.n[0] * b.n[0], a.n[1] * b.n[1], a.n[2] * b.n[2]);
}

inline vec3 operator/(const vec3& a, const vec3& b) {
  return vec3(a.n[0] / b.n[0], a.n[1] / b.n[1], a.n[2] / b.n[2]);
}

inline vec3 operator*(const vec3& v, double t) {
  return vec3(v.n[0] * t, v.n[1] * t, v.n[2] * t);
}
inline vec3 operator*(double t, const vec3& v) { return v * t; }
inline vec3 operator/(const vec3& v, double t) { return v * (1 / t); }

inline double dot(const vec3& a, const vec3& b) {
  return a.n[0] * b.n[0] + a.n[1] * b.n[1] + a.n[2] * b.n[2];
}

inline vec3 cross(const vec3& a, const vec3& b) {
  return vec3(a.n[1] * b.n[2] - a.n[2] * b.n[1],
              a.n[2] * b.n[0] - a.n[0] * b.n[2],
              a.n[0] * b.n[1] - a.n[1] * b.n[0]);
}

inline vec3 normalize(const vec3& v) {
  return v / v.length();
}

#endif