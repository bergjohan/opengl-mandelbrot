#include "image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Image::Image(const char *filename) {
  int height{};
  int channels_in_file{};
  data_ = stbi_load(filename, &width_, &height, &channels_in_file, 0);
}

Image::~Image() { stbi_image_free(data_); }

int Image::width() const { return width_; }

unsigned char *Image::data() const { return data_; }
