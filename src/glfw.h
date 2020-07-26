#pragma once

class GLFW {
public:
  GLFW();
  ~GLFW();
  GLFW(const GLFW &) = delete;
  GLFW &operator=(const GLFW &) = delete;
  GLFW(GLFW &&) = delete;
  GLFW &operator=(GLFW &&) = delete;
};
