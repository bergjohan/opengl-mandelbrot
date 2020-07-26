#include "texture.h"

Texture::Texture() { glGenTextures(1, &id_); }

Texture::~Texture() { glDeleteTextures(1, &id_); }

void Texture::bind() const {
  glBindTexture(GL_TEXTURE_1D, id_);
  glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
