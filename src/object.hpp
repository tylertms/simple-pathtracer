#ifndef OBJECT_HPP
#define OBJECT_HPP

constexpr double min_ray_time = 1e-6;
constexpr double max_ray_time = 1e+6;

class hit {
 public:
  point3 point;
  vec3 normal;
  double time;
  bool is_front;

  void set_face_normal(const ray& r, const vec3& outward_normal) {
    is_front = dot(r.direction(), outward_normal) < 0;
    normal = is_front ? outward_normal : -outward_normal;
  }
};

class object {
 public:
  virtual ~object() = default;
  virtual bool intersection(const ray& r, double min_t, double max_t, hit& h) const = 0;
};

#endif