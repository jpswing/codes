n = 16
names = []
for _ in range(n):
    names.append(input())
a = []
for i in range(n):
    a.append(list(map(lambda x: int(x) / 100, input().split())))

dp = [[0] * n for _ in range(4)]
for i in range(n):
    dp[0][i] = a[i][i ^ 1]

for i in range(1, 4):
    for j in range(n):
        length = (1<<i)
        start = j // length
        start ^= 1
        start *= length
        # print(start, i, j)
        for k in range(start, start + length):
            dp[i][j] += (dp[i - 1][k] if i > 0 else 1) * a[j][k]
        dp[i][j] *= (dp[i - 1][j] if i > 0 else 1)
        # print(i, j, dp[i][j])

for i in range(n):
    print('{:10} p={:.2%}'.format(names[i], dp[3][i]))

