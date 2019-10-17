n = int(input())
p = []
for _ in range(n):
    x, y = input().split()
    p.append((int(x), int(y)))

k = []

from math import gcd
def getk(x1, y1, x2, y2):
    if x1 == x2: return (1, 0)
    if y1 == y2: return (0, 1)
    num = y2 - y1
    den = x2 - x1
    g = gcd(abs(num), abs(den))
    num //= g
    den //= g
    if den < 0:
        num = -num
        den = -den
    return (num, den)

for i in range(n):
    tk = {}
    for j in range(n):
        if i == j: continue
        tmp = getk(*p[i], *p[j])
        tk[getk(*p[i], *p[j])] = tk.get(tmp, 0) + 1
    k.append(tk)

ans = 0

for i in range(n):
    for j in range(i + 1, n):
        ans += n - 1 - k[i][getk(*p[i], *p[j])]

print(ans // 3)
# print(k)

