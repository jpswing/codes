T = int(input())
while T:
    T -= 1
    n, k = map(int, input().split())
    dp = [[0] * (k + 1) for _ in range(1 << n)]
    dp[0][0] = 1
    for i in range(0, (1 << n) - 1):
        for j in range(0, k + 1):
            cnt = 0
            for x in range(n - 1, -1, -1):
                if i & (1 << x):
                    cnt += 1
                    continue
                mask = i | (1 << x)
                if j + cnt > k: break
                dp[mask][j + cnt] += dp[i][j]
    # for i in range(1 << n):
    #     print(bin(i), dp[i])
    print(dp[(1 << n) - 1][k])

