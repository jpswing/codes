a, w, h, n = map(int, input().split())

p = []
for _ in range(n):
    x, y = map(int, input().split())
    p.append((x, y))

import math

def rotate(x, y, deg):
    deg = deg * math.pi / 180
    s = math.sin(deg)
    c = math.cos(deg)
    return x * c - y * s, x * s + y * c

p = [rotate(*x, a) for x in p]

off = min(p, key=lambda x: x[0])[0]
p = [(x - off, y) for x, y in p]
frac = w / max(p, key=lambda x: x[0])[0]
p = [(x * frac, y) for x, y in p]

off = min(p, key=lambda x: x[1])[1]
p = [(x, y - off) for x, y in p]
frac = h / max(p, key=lambda x: x[1])[1]
p = [(x, y * frac) for x, y in p]

for i in p:
    print(i[0], i[1])

