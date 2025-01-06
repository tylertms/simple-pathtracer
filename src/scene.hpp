#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>

class scene : public object {
  public:
  std::vector<std::shared_ptr<object>> objects;

  scene() {}
  scene(shared_ptr<object> obj) { add(obj); }

  void clear() { objects.clear(); }

  void add(shared_ptr<object> obj) {
    objects.push_back(obj);
  }

  bool intersection(const ray& r, double min_t, double max_t, hit& h) const override {
    hit temp_hit;
    bool did_hit = false;
    double closest_time = max_t;

    for (const auto& obj : objects) {
      if (obj->intersection(r, min_t, closest_time, temp_hit)) {
        did_hit = true;
        closest_time = temp_hit.time;
        h = temp_hit;
      }
    }

    return did_hit;
  }
};

#endif