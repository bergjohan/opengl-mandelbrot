#pragma once

#include "glad/glad.h"

class Texture {
public:
  Texture();
  ~Texture();
  Texture(const Texture &) = delete;
  Texture &operator=(const Texture &) = delete;
  Texture(Texture &&) = delete;
  Texture &operator=(Texture &&) = delete;
  void bind() const;

private:
  GLuint id_{};
};

template <typename T> void tex_image(GLsizei width, T *data) {
  glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, width, 0, GL_RGB, GL_UNSIGNED_BYTE,
               data);
}
