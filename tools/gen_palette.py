#!/usr/bin/env python3

from PIL import Image

# Perform a linear interpolation between x and y using a to weight between them
def lerp(x, y, a):
    return (int(x[0] * (1 - a) + y[0] * a),
            int(x[1] * (1 - a) + y[1] * a),
            int(x[2] * (1 - a) + y[2] * a))

im = Image.new("RGB", (500, 1))
pixels = im.load()
count = int(im.width / 4)
a = 0.0
for i in range(count):
    pixels[i, 0] = lerp((0, 0, 0), (0, 0, 255), a)
    a += 1 / count
a = 0.0
for i in range(count):
    pixels[i + count, 0] = lerp((0, 0, 255), (255, 255, 255), a)
    a += 1 / count
a = 0.0
for i in range(count):
    pixels[i + count * 2, 0] = lerp((255, 255, 255), (0, 0, 255), a)
    a += 1 / count
a = 0.0
for i in range(count):
    pixels[i + count * 3, 0] = lerp((0, 0, 255), (0, 0, 0), a)
    a += 1 / count
im.save("palette.jpg")
