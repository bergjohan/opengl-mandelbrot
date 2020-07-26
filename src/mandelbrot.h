#pragma once

#include "shader.h"
#include "texture.h"
#include "vertex_buffer.h"
#include "window.h"

class Mandelbrot : public Event_listener {
public:
  explicit Mandelbrot(Window *window);
  void framebuffer_size_callback(int width, int height) const override;

private:
  Program program_{};
  Vertex_buffer vbo_{};
  Texture texture_{};
};

void draw();
