#include <fstream>
#include <iostream>
using namespace std;

#define FILE_NAME_LENGTH 32

#define IMG_WIDTH 1024
#define IMG_HEIGHT 1024

#include "color.hpp"
#include "ray.hpp"

color ray_color(ray& r) {
  vec3 unit_dir = normalized(r.direction());
  double a = (unit_dir.y() + 1.0) * 0.5;
  return (a)*color(1.0, 1.0, 1.0) + (1-a)*color(0.5, 0.7, 1.0);
}

int main(int argc, char* argv[]) {
  // set up file name
  char file_name[FILE_NAME_LENGTH] = "image.ppm";
  if (argc > 1) {
    strncpy(file_name, argv[1], FILE_NAME_LENGTH);
    file_name[FILE_NAME_LENGTH - 1] = '\0';
  }

  // create and open image file
  ofstream image(file_name);
  if (!image.is_open()) {
    printf("Error creating file: %s\n", file_name);
    return -1;
  }

  // write .ppm image header
  image << "P6\n";
  image << IMG_WIDTH <<  " " << IMG_HEIGHT << "\n";
  image << UINT8_MAX << "\n";

  // camera info
  double focal_length = 2.0;
  point3 camera_origin =  vec3(0, 0, -focal_length);


  for (int y = 0; y < IMG_HEIGHT; y++) {
    clog << "\r" << y << " / " << IMG_HEIGHT << " lines rendered." << flush;

    for (int x = 0; x < IMG_WIDTH; x++) {
      // get ray from camera to point
      point3 pixel_point = vec3((double)(2 * x - IMG_WIDTH) / IMG_WIDTH, (double)(2 * y - IMG_HEIGHT) / IMG_HEIGHT, 0);
      vec3 ray_direction = pixel_point - camera_origin;
      ray r(camera_origin, ray_direction);
      
      color pixel_color = ray_color(r);
      write_color(image, pixel_color);
    }
  }

  std::clog << "\rSuccessfully rendered image: " << file_name << "\n";

  // close out the image
  image.close();

  return 0;
}