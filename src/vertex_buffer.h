#pragma once

#include "glad/glad.h"

class Vertex_buffer {
public:
  Vertex_buffer();
  ~Vertex_buffer();
  Vertex_buffer(const Vertex_buffer &) = delete;
  Vertex_buffer &operator=(const Vertex_buffer &) = delete;
  Vertex_buffer(Vertex_buffer &&) = delete;
  Vertex_buffer &operator=(Vertex_buffer &&) = delete;
  void bind() const;

private:
  GLuint id_{};
};

template <typename T> void buffer_data(GLsizeiptr size, T *data) {
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
