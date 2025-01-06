#include <fstream>
#include <iostream>
using namespace std;

#define FILE_NAME_LENGTH 32

#define IMG_WIDTH 1024
#define IMG_HEIGHT 1024

#include "color.hpp"

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

  for (int y = 0; y < IMG_HEIGHT; y++) {
    clog << "\r" << y << " / " << IMG_HEIGHT << " lines rendered." << flush;

    for (int x = 0; x < IMG_WIDTH; x++) {
      auto pixel_color = color((double)x / IMG_WIDTH, (double)y / IMG_HEIGHT, 0);
      write_color(image, pixel_color);
    }
  }

  std::clog << "\rSuccessfully rendered image: " << file_name << "\n";

  // close out the image
  image.close();

  return 0;
}