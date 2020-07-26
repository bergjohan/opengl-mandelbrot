#include "mandelbrot.h"

#include <array>
#include <fstream>

#include "image.h"
#include <glm/gtc/type_ptr.hpp>

namespace {

std::string read_file(const char *filename) {
  std::ifstream is{};
  is.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  is.open(filename);
  return std::string{std::istreambuf_iterator<char>{is},
                     std::istreambuf_iterator<char>{}};
}

} // namespace

Mandelbrot::Mandelbrot(Window *window) {
  window->add_event_listener(this);

  const std::string vertex_shader_source = read_file("mandelbrot.vert");
  const std::string fragment_shader_source = read_file("mandelbrot.frag");

  Shader vertex_shader = compile_vertex_shader(vertex_shader_source.c_str());
  Shader fragment_shader =
      compile_fragment_shader(fragment_shader_source.c_str());

  program_.attach(vertex_shader);
  program_.attach(fragment_shader);
  program_.link();
  program_.use();

  const std::array<float, 9> vertices = {
      -1.0f, -1.0f, 0.0f,
      3.0f, -1.0f, 0.0f,
      -1.0f, 3.0f, 0.0f
  };

  vbo_.bind();
  buffer_data(sizeof(vertices), vertices.data());

  Image image{"palette.jpg"};
  texture_.bind();
  tex_image(image.width(), image.data());

  const GLint index = program_.attrib_location("a_pos");
  glVertexAttribPointer(static_cast<GLuint>(index), 3, GL_FLOAT, GL_FALSE,
                        3 * sizeof(float), nullptr);
  glEnableVertexAttribArray(static_cast<GLuint>(index));

  glm::mat4 trans = glm::ortho(-2.2f, 1.0f, -1.2f, 1.2f, -1.0f, 1.0f);
  trans = glm::inverse(trans);
  glUniformMatrix4fv(program_.uniform_location("u_trans"), 1, GL_FALSE,
                     glm::value_ptr(trans));

  glUniform1i(program_.uniform_location("u_palette"), 0);
}

void Mandelbrot::framebuffer_size_callback(int width, int height) const {
  glViewport(0, 0, width, height);
}

void draw() { glDrawArrays(GL_TRIANGLES, 0, 3); }
