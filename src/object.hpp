#ifndef OBJECT_HPP
#define OBJECT_HPP

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
  virtual bool intersection(const ray& r, range t_limit, hit& h) const = 0;
};

#endif