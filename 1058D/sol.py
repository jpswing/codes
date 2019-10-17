n, m, k = map(int, input().split())

if 2 * n * m % k != 0:
    print('NO')
    exit()

from math import gcd

if k % 2 == 0: k //= 2
elif gcd(n, k) > 1: n *= 2
else: m *= 2

x = n // gcd(n, k)
y = m // (k // gcd(n, k))

print('YES')
print('0 0')
print(x, '0')
print('0', y)

