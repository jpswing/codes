try:
    while True:
        k = int(input())
        a = [list(map(int, input().split())) for _ in range(k)]
        for i in a: i.sort()
        b = [[a[i][j] - a[i][j - 1] for j in range(1, k)] for i in range(k)]
        # print(a)
        # print(b)
        ans = [sum(a[i][0] for i in range(k))]
        ptr = [0] * k
        q = []
        for i in range(k): q.append(i)
        for i in range(k - 1):
            q.sort(key=lambda x: b[x][ptr[x]])
            ans.append(ans[-1] + b[q[0]][ptr[q[0]]])
            ptr[q[0]] += 1
        print(' '.join(str(i) for i in ans))

except EOFError:
    pass
