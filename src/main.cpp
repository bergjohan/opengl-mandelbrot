#include <iostream>

#include "glfw.h"
#include "mandelbrot.h"

int main() {
  GLFW glfw{};

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

  const int width = 800;
  const int height = 600;
  Window window{width, height, "Mandelbrot"};

  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    std::cerr << "Failed to initialize OpenGL context\n";
    return 1;
  }

  Mandelbrot mandelbrot{&window};

  while (!window.should_close()) {
    draw();
    window.swap_buffers();
    glfwWaitEvents();
  }
}
