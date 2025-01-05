#include <iostream>
#include <fstream>
using namespace std;

#define FILE_NAME_LENGTH  32

#define IMG_WIDTH  1024
#define IMG_HEIGHT 1024

int main(int argc, char* argv[]) {
  // set up file name
  char fileName[FILE_NAME_LENGTH] = "image.ppm";
  if (argc > 1) {
    strncpy(fileName, argv[1], FILE_NAME_LENGTH);
    fileName[FILE_NAME_LENGTH - 1] = '\0';
  }

  // create and open image file
  ofstream image(fileName);
  if (!image.is_open()) {
    printf("Error creating file: %s\n", fileName);
    return -1;
  }

  // write .ppm image header
  image << "P6\n" << IMG_WIDTH << " " << IMG_HEIGHT << "\n255\n";

  for (int y = 0; y < IMG_HEIGHT; y++) {
    for (int x = 0; x < IMG_WIDTH; x++) {
      image << (unsigned char)((float)x * 255.99 / IMG_WIDTH);
      image << (unsigned char)((float)y * 255.99 / IMG_HEIGHT);
      image << '\0';
    }
  }

  // close out the image
  image.close();

  return 0;
}