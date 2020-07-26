#pragma once

#include <GLFW/glfw3.h>

class Window;

class Event_listener {
public:
  virtual void framebuffer_size_callback(int width, int height) const = 0;

protected:
  Event_listener() = default;
  ~Event_listener() = default;
  Event_listener(const Event_listener &) = default;
  Event_listener &operator=(const Event_listener &) = default;
  Event_listener(Event_listener &&) = default;
  Event_listener &operator=(Event_listener &&) = default;
};

class Window {
public:
  Window(int width, int height, const char *title);
  ~Window();
  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;
  Window(Window &&) = delete;
  Window &operator=(Window &&) = delete;
  void add_event_listener(Event_listener *listener);
  Event_listener *listener() const;
  bool should_close() const;
  void swap_buffers() const;

private:
  GLFWwindow *handle_{};
  Event_listener *listener_{};
};
