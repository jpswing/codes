t = int(input())
from math import pow

for cs in range(t):
    n, k, m = map(int, input().split())
    p = [float(input()) for _ in range(n)]
    if m == 0:
        print('Case #{}: {:.10f}'.format(cs + 1, 0))
        continue
    dp = [0] * (m + 1)
    dp[1] = p[0]
    for i in range(2, m + 1):
        for j in range(n):
            # print(dp[i - 1], j)
            dp[i] += pow(dp[i - 1], j) * p[j];
            # print(dp)
    ans = pow(dp[m], k)
    print('Case #{}: {:.10f}'.format(cs + 1, ans))
