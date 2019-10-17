n = int(input())

a = [int(x) for x in input().split(' ')]

INF = 1<<30
mn = [INF] * n
for i in range(n - 1, -1, -1):
    mn[i] = min(a[i], mn[i + 1] if i + 1 < n else INF)

# print(mn)

for i in range(n):
    l = i
    r = n - 1
    while l < r:
        mid = r - (r - l) // 2
        if (mn[mid] >= a[i]): r = mid - 1
        else: l = mid
    print(l - i - 1, end=' ')

