n, m = map(int, input().split())

a = []
pos = [[0] * n for _ in range(m)]

for i in range(m):
    tmp = [x - 1 for x in map(int, input().split())]
    # print(tmp)
    a.append(tmp)
    for j, x in enumerate(tmp): 
        pos[i][x] = j
# print(pos)

prev = [-1] * m

ans = 0
cnt = 0
for i in range(n):
    # print(prev)
    v = a[0][i]
    # print(v)
    if all(pos[j][v] == prev[j] + 1 or prev[j] == -1 for j in range(m)):
        cnt += 1
    else:
        cnt = 1
    ans += cnt
    prev = [pos[j][v] for j in range(m)]

print(ans)

