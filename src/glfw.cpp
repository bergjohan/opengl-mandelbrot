#include "glfw.h"

#include <stdexcept>

#include <GLFW/glfw3.h>

GLFW::GLFW() {
  if (!glfwInit()) {
    throw std::runtime_error{"Failed to initialize the GLFW library"};
  }
}

GLFW::~GLFW() { glfwTerminate(); }
