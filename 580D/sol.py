from itertools import combinations

n, m, k = map(int, input().split())
a = list(map(int, input().split()))

g = []
for _ in range(k):
    g.append(tuple(map(int, input().split())))
# print(g)

for comb in combinations(a, m):
    print(comb)
