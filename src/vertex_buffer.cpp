#include "vertex_buffer.h"

Vertex_buffer::Vertex_buffer() { glGenBuffers(1, &id_); }

Vertex_buffer::~Vertex_buffer() { glDeleteBuffers(1, &id_); }

void Vertex_buffer::bind() const { glBindBuffer(GL_ARRAY_BUFFER, id_); }
