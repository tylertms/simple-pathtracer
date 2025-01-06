#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "config.hpp"
#include "object.hpp"

class camera {
 public:
  int image_width = 1024;
  double aspect_ratio = 16.0 / 10.0;
  double focal_length = 1.0;

  void render(const object& scn, std::ostream& image) {
    init(image);

    for (int y = 0; y < image_height; y++) {
      clog << "\r" << y << " / " << image_height << " lines rendered." << flush;

      for (int x = 0; x < image_width; x++) {
        // get ray from camera to point
        point3 pixel_point = vec3((double)(2 * x - image_width) / min_view_len,
                                  (double)(2 * y - image_height) / -min_view_len, -focal_length);
        vec3 ray_direction = camera_origin - pixel_point;
        ray r(pixel_point, ray_direction);

        // get color from that ray and write to the image
        color pixel_color = ray_color(r, scn);
        write_color(image, pixel_color);
      }
    }
  }

 private:
  int image_height;
  int min_view_len;
  point3 camera_origin;

  void init(std::ostream& image) {
    image_height = int(image_width / aspect_ratio);
    min_view_len = min(image_width, image_height);
    camera_origin = vec3(0, 0, 0);

    // write .ppm image header
    image << "P6\n";
    image << image_width << " " << image_height << "\n";
    image << UINT8_MAX << "\n";
  }

  color ray_color(const ray& r, const object& scn) const {
    // check for intersections
    hit h;
    if (scn.intersection(r, range(0, infinity), h)) {
      return 0.5 * (h.normal + color(1, 1, 1));
    }
    // otherwise, get a sky color for that direction
    vec3 unit_dir = normalize(r.direction());
    double a = (unit_dir.y() + 1.0) * 0.5;
    return (a)*color(1.0, 1.0, 1.0) + (1 - a) * color(0.5, 0.7, 1.0);
  }
};

#endif