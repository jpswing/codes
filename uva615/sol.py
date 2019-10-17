finished = False
cs = 0
while True:
    cs += 1
    es = []
    while True:
        edges = list(map(int, input().split()))
        if not edges: continue
        es += edges
        if edges[-1] == 0: break
        if edges[-1] < 0:
            finished = True
            break

    if finished: break
    del es[-2:]
    mp = {}
    cnt = 0
    # print(es)
    for i in range(0, len(es)):
        if es[i] not in mp:
            mp[es[i]] = cnt
            cnt += 1
        es[i] = mp[es[i]]
    # print(es)
    n = max(es, default=0) + 1

    if len(es) // 2 != n - 1:
        print('Case {} is not a tree.'.format(cs))
        continue
    g = [[] for _ in range(n)]
    for i in range(0, len(es), 2):
        g[es[i]].append(es[i + 1])
    vis = [0] * n
    def dfs(u):
        if vis[u]: return
        vis[u] = 1
        for v in g[u]:
            dfs(v)
    deg = [0] * n
    for i in range(0, len(es), 2):
        deg[es[i + 1]] += 1
    for i in range(n):
        if deg[i] == 0:
            dfs(i)
            break
    if sum(vis) == n:
        print('Case {} is a tree.'.format(cs))
    else:
        print('Case {} is not a tree.'.format(cs))

    # cnt = [0] * n
    # for i in deg: cnt[i] += 1
    # # print(deg)
    # if n == 1 or cnt[0] == 1 and cnt[1] == n - 1:
    #     print('Case {} is a tree.'.format(cs))
    # else:
    #     print('Case {} is not a tree.'.format(cs))
    
