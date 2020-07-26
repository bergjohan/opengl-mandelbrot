#include "window.h"

#include <stdexcept>

namespace {

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  const Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
  w->listener()->framebuffer_size_callback(width, height);
}

} // namespace

Window::Window(int width, int height, const char *title) {
  handle_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!handle_) {
    throw std::runtime_error{"Failed to create a window"};
  }

  glfwMakeContextCurrent(handle_);
  glfwSetWindowUserPointer(handle_, this);
}

Window::~Window() { glfwDestroyWindow(handle_); }

void Window::add_event_listener(Event_listener *listener) {
  glfwSetFramebufferSizeCallback(handle_, framebuffer_size_callback);
  listener_ = listener;
}

Event_listener *Window::listener() const { return listener_; }

bool Window::should_close() const { return glfwWindowShouldClose(handle_); }

void Window::swap_buffers() const { glfwSwapBuffers(handle_); }
