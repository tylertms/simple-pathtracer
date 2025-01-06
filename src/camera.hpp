#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "config.hpp"
#include "object.hpp"

class camera {
 public:
  double focal_length = 1.0;

  void render(const object& scn, std::ostream& image) {
    init(image);

    for (int y = 0; y < IMG_HEIGHT; y++) {
      clog << "\r" << y << " / " << IMG_HEIGHT << " lines rendered." << flush;

      for (int x = 0; x < IMG_WIDTH; x++) {
        // get ray from camera to point
        point3 pixel_point = vec3((double)(2 * x - IMG_WIDTH) / min_dir,
                                  (double)(2 * y - IMG_HEIGHT) / min_dir, -focal_length);
        vec3 ray_direction = camera_origin - pixel_point;
        ray r(pixel_point, ray_direction);

        // get color from that ray and write to the image
        color pixel_color = ray_color(r, scn);
        write_color(image, pixel_color);
      }
    }
  }

 private:
  point3 camera_origin = vec3(0, 0, 0);

  int min_dir = -min(IMG_HEIGHT, IMG_WIDTH);

  void init(std::ostream& image) {
    // write .ppm image header
    image << "P6\n";
    image << IMG_WIDTH << " " << IMG_HEIGHT << "\n";
    image << UINT8_MAX << "\n";
  }

  color ray_color(const ray& r, const object& scn) const {
    // check for intersections
    hit h;
    if (scn.intersection(r, range(0, infinity), h)) {
      return 0.5 * (-h.normal + color(1, 1, 1));
    }
    // otherwise, get a sky color for that direction
    vec3 unit_dir = normalize(r.direction());
    double a = (unit_dir.y() + 1.0) * 0.5;
    return (a)*color(1.0, 1.0, 1.0) + (1 - a) * color(0.5, 0.7, 1.0);
  }
};

#endif