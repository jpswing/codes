t = int(input())

while t:
    t -= 1
    n = int(input())
    p = float(input())
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = pow(p, i)
        dp[0][i] = pow(1 - p, i)
    # print(dp)
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i == n:
                dp[i][j] = dp[i - 1][j] * p
            elif j == n:
                dp[i][j] = dp[i][j - 1] * (1 - p)
            else:
                dp[i][j] = dp[i - 1][j] * p + dp[i][j - 1] * (1 - p);
    # print(dp[1][1])
    # print([dp[n][i] for i in range(n)])
    print('{:.2f}'.format(sum(dp[n][i] for i in range(n))))

