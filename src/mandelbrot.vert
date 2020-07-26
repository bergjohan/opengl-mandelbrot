#version 120

attribute vec3 a_pos;
uniform mat4 u_trans;
varying vec2 v_pos;

void main() {
  gl_Position = vec4(a_pos.xyz, 1.0);
  v_pos = (u_trans * vec4(a_pos.xyz, 1.0)).xy;
}
