#pragma once

class Image {
public:
  explicit Image(const char *filename);
  ~Image();
  Image(const Image &) = delete;
  Image &operator=(const Image &) = delete;
  Image(Image &&) = delete;
  Image &operator=(Image &&) = delete;
  int width() const;
  unsigned char *data() const;

private:
  int width_{};
  unsigned char *data_{};
};
