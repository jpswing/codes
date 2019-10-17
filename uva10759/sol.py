from fractions import Fraction

while True:
    n, x = map(int, input().split())
    if n == 0 and x == 0: break
    dp = [[0] * (150 + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(1, n + 1):
        for j in range(1, 150 + 1):
            for k in range(1, 6 + 1):
                if j < k: break
                dp[i][j] += dp[i - 1][j - k] * Fraction(1, 6)
    ans = Fraction()
    for i in range(x, 150 + 1):
        ans += dp[n][i]
    print(ans)

