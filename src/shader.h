#pragma once

#include "glad/glad.h"

class Shader {
public:
  Shader(GLenum shader_type, const char *source);
  ~Shader();
  Shader(const Shader &) = delete;
  Shader &operator=(const Shader &) = delete;
  Shader(Shader &&) = delete;
  Shader &operator=(Shader &&) = delete;
  GLuint get() const;

private:
  GLuint id_{};
};

Shader compile_vertex_shader(const char *source);
Shader compile_fragment_shader(const char *source);

class Program {
public:
  Program();
  ~Program();
  Program(const Program &) = delete;
  Program &operator=(const Program &) = delete;
  Program(Program &&) = delete;
  Program &operator=(Program &&) = delete;
  void attach(const Shader &shader) const;
  void link() const;
  void use() const;
  GLint attrib_location(const char *name) const;
  GLint uniform_location(const char *name) const;

private:
  GLuint id_{};
};
