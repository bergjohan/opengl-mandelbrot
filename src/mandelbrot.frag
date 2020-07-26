#version 120

varying vec2 v_pos;
uniform sampler1D u_palette;

void main() {
  float x0 = v_pos.x;
  float y0 = v_pos.y;
  float x = 0;
  float y = 0;
  float x2 = 0;
  float y2 = 0;
  int iteration = 0;
  int max_iteration = 100;

  while (x2 + y2 <= 20.0 && iteration < max_iteration) {
    y = 2 * x * y + y0;
    x = x2 - y2 + x0;
    x2 = x * x;
    y2 = y * y;
    iteration++;
  }

  if (x2 + y2 <= 20.0) {
    gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
  } else {
    // See http://linas.org/art-gallery/escape/escape.html
    float mu = iteration - log(log(x2 + y2)) / log(2.0);
    gl_FragColor = texture1D(u_palette, mu / max_iteration);
  }
}
