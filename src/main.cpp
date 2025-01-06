#include "config.hpp"
#include "sphere.hpp"
#include "scene.hpp"
#include "camera.hpp"

using std::make_shared;
using std::shared_ptr;


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

  // scene setup
  scene scn;
  scn.add(make_shared<sphere>(point3(0, 0, 1), 0.5));
  scn.add(make_shared<sphere>(point3(0,100.5,10), 100));

  camera cam;
  cam.focal_length = 1;
  cam.render(scn, image);

  std::clog << "\rSuccessfully rendered image: " << file_name << "\n";

  // close out the image
  image.close();

  return 0;
}