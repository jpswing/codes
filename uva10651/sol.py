n = int(input())
for _ in range(n):
    start = 0
    s = input()
    for i in range(12):
        if s[i] == 'o':
            start |= (1<<i)
    dp = [0] * (1 << 12)
    def count1(mask):
        res = 0
        for i in range(12):
            if mask & (1<<i):
                res += 1
        return res
    def getbit(mask, i):
        return (mask >> i) & 1
    ans = 20
    def dfs(mask):
        global ans
        if dp[mask]: return
        dp[mask] = 1
        # print(count1(mask))
        ans = min(ans, count1(mask))
        for i in range(12):
            if i > 1 and getbit(mask, i) == 1 and getbit(mask, i - 1) == 1 and getbit(mask, i - 2) == 0:
                new_mask = mask
                new_mask ^= (1<<i)
                new_mask ^= (1<<(i - 1))
                new_mask |= (1<<(i - 2))
                dfs(new_mask)
            if i < 12 - 2 and getbit(mask, i) == 1 and getbit(mask, i + 1) == 1 and getbit(mask, i + 2) == 0:
                new_mask = mask
                new_mask ^= (1<<i)
                new_mask ^= (1<<(i + 1))
                new_mask |= (1<<(i + 2))
                dfs(new_mask)
    dfs(start)
    print(ans)

