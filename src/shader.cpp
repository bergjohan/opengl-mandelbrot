#include "shader.h"

#include <stdexcept>
#include <vector>

Shader::Shader(GLenum shader_type, const char *source) {
  id_ = glCreateShader(shader_type);
  glShaderSource(id_, 1, &source, nullptr);
  glCompileShader(id_);

  GLint success{};
  glGetShaderiv(id_, GL_COMPILE_STATUS, &success);
  if (!success) {
    GLint max_length{};
    glGetShaderiv(id_, GL_INFO_LOG_LENGTH, &max_length);
    std::vector<GLchar> info_log(static_cast<std::size_t>(max_length));
    glGetShaderInfoLog(id_, max_length, nullptr, &info_log[0]);
    glDeleteShader(id_);
    throw std::runtime_error{std::string{info_log.begin(), info_log.end()}};
  }
}

Shader::~Shader() { glDeleteShader(id_); }

GLuint Shader::get() const { return id_; }

Shader compile_vertex_shader(const char *source) {
  return Shader{GL_VERTEX_SHADER, source};
}

Shader compile_fragment_shader(const char *source) {
  return Shader{GL_FRAGMENT_SHADER, source};
}

Program::Program() { id_ = glCreateProgram(); }

Program::~Program() { glDeleteProgram(id_); }

void Program::attach(const Shader &shader) const {
  glAttachShader(id_, shader.get());
}

void Program::link() const {
  glLinkProgram(id_);

  GLint success{};
  glGetProgramiv(id_, GL_LINK_STATUS, &success);
  if (!success) {
    GLint max_length{};
    glGetProgramiv(id_, GL_INFO_LOG_LENGTH, &max_length);
    std::vector<GLchar> info_log(static_cast<std::size_t>(max_length));
    glGetProgramInfoLog(id_, max_length, nullptr, &info_log[0]);
    throw std::runtime_error{std::string{info_log.begin(), info_log.end()}};
  }
}

void Program::use() const { glUseProgram(id_); }

GLint Program::attrib_location(const char *name) const {
  return glGetAttribLocation(id_, name);
}

GLint Program::uniform_location(const char *name) const {
  return glGetUniformLocation(id_, name);
}
