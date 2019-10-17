n = int(input())
a = [int(x) for x in input().split(' ')]

if len(a) == 1:
    print(a[0])
    exit()

a.sort()

if all(x > 0 for x in a):
    print(sum(a) - a[0] * 2)
    exit()

if all(x < 0 for x in a):
    print(-sum(a) + a[-1] * 2)
    exit()

print(sum(abs(x) for x in a))

