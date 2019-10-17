dp = [0]
def count_num(v):
    ans = 1
    v //= 10
    while v > 0:
        ans += 1
        v //= 10
    return ans

i = 1
pref = [0]
while True:
    val = dp[i - 1] + count_num(i)
    dp.append(val)
    pref.append(pref[i - 1] + val)
    if pref[-1] >= (1<<31):
        break
    i += 1


t = int(input())

while t > 0:
    t -= 1
    n = int(input())
    l = 0
    r = len(pref) - 1
    while l < r:
        mid = r - (r - l) // 2
        if pref[mid] < n:
            l = mid
        else:
            r = mid - 1
    n -= pref[l]
    # print(n)
    r = l + 1
    l = 0
    while l < r:
        mid = r - (r - l) // 2
        if dp[mid] < n:
            l = mid
        else:
            r = mid - 1
    # print(l)
    n -= dp[l]
    # print(n)
    print(str(l + 1)[n - 1])
    

