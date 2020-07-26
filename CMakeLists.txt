cmake_minimum_required(VERSION 3.1)
project(opengl-mandelbrot LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PRIVATE external/glad/include)

add_executable(mandelbrot
  src/glfw.cpp
  src/image.cpp
  src/main.cpp
  src/mandelbrot.cpp
  src/shader.cpp
  src/texture.cpp
  src/vertex_buffer.cpp
  src/window.cpp
)
target_include_directories(mandelbrot PRIVATE external/glad/include)
# Specify SYSTEM to prevent warnings from stb headers
target_include_directories(mandelbrot SYSTEM PRIVATE external/stb)
target_compile_features(mandelbrot PRIVATE cxx_std_17)
set_target_properties(mandelbrot PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(mandelbrot PRIVATE
  -Werror
  -pedantic-errors
  -Wall
  -Wextra
  -Wconversion
  -Wsign-conversion
)
find_package(glfw3 REQUIRED)
target_link_libraries(mandelbrot PRIVATE glad glfw ${CMAKE_DL_LIBS})

add_custom_command(TARGET mandelbrot
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_SOURCE_DIR}/src/mandelbrot.vert
  ${CMAKE_BINARY_DIR}/mandelbrot.vert
)

add_custom_command(TARGET mandelbrot
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_SOURCE_DIR}/src/mandelbrot.frag
  ${CMAKE_BINARY_DIR}/mandelbrot.frag
)

add_custom_command(TARGET mandelbrot
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_SOURCE_DIR}/data/palette.jpg
  ${CMAKE_BINARY_DIR}/palette.jpg
)
