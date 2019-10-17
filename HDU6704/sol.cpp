#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <tuple>
#include <functional>
#include <queue>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;

#define name(x) #x": " << (x) << ' '

struct SuffixArray {
    int n;
    int arr[N];
    int sa[N];
    int rank[N];
    int lcp[N]; // LCP between sa[i] and sa[i-1]
    int t1[N], t2[N], cnt[N];

    void init (const string &s) {
        n = 0;
        for (auto i : s) arr[n++] = i;
        arr[n++] = 0;
        build_sa(127);
//        build();
        build_lcp();
    }

    // m为最大字符集数加1
    void build_sa(int m) {
        int *x = t1, *y = t2;
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) ++cnt[x[i] = arr[i]];
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; --i) sa[--cnt[x[i]]] = i;
        for (int k = 1; k <= n; k <<= 1) {
            int p = 0;

            // 按照次关键字进行排序
            for (int i = n - k; i < n; i++) y[p++] = i;
            for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;

            // 按照主关键字进行排序
            for (int i = 0; i < m; i++) cnt[i] = 0;
            for (int i = 0; i < n; i++) ++cnt[x[y[i]]];
            for (int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) sa[--cnt[x[y[i]]]] = y[i];
            swap(x, y);

            // 计算rank
            p = 1;
            x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]
                            ? p - 1 : p++);
            if (p >= n) break;
            m = p;
        }
        for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    }

    void build_lcp() {
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(k) k--;
            if(rank[i] - 1 < 0) continue; // rank[i]可能是0
            int j = sa[rank[i]-1];
            while(arr[i+k] == arr[j+k]) k++;
            lcp[rank[i]] = k;
        }
    }

    // 所有height值之和为重复子串的个数
    // 同一子串会在后缀数组中连续出现
} sa;

struct node {
	int l, r; // pointers to l & r subtree
	int cnt;
	node() : l(-1), r(-1), cnt(0) {}
} pool[N * 20]; // 节点静态内存池

int n, q;
int cnt; // 内存池的指针
int roots[N]; // 可持久化线段树

int query(int l, int r, int x, int y, int k) {
	if (x == y) return x;
	int dif = (pool[pool[r].l].cnt - pool[pool[l].l].cnt); // 原序列[l,r]区间中的该节点元素个数
    // cout << name(x) << name(y) << name(dif) << endl;
	int h = (x + y) >> 1;
    // cout << name(x) << name(h) << name(dif) << endl;
	if (k <= dif) return query(pool[l].l, pool[r].l, x, h, k); // 说明第k小的值在左子树
	return query(pool[l].r, pool[r].r, h + 1, y, k - dif); // 否则在右子树，此时k要减去dif
}
void add(int s, int t, int x, int y, int v) {
	// s代表上一版本的节点，t代表当前版本的节点
	pool[t] = pool[s]; // 复制上一版本的节点
	++pool[t].cnt; // 修改
	if (x == y) return;
	int h = (x + y) >> 1;
	if (v <= h)
		add(pool[s].l, pool[t].l = ++cnt, x, h, v); // 要修改的值属于左子树，更新该版本的节点的左子树
	else
		add(pool[s].r, pool[t].r = ++cnt, h + 1, y, v);
}
void build(int u, int x, int y) {
	pool[u] = node();
	if (x == y) return;
	int h = (x + y) >> 1;
	build(pool[u].l = ++cnt, x, h);
	build(pool[u].r = ++cnt, h + 1, y);
}
void init() {
	build(roots[0] = cnt = 0, 0, n);
}
int minima[20][N];
void init_st(const vector<int> &a) {
    for (int i = 0; i < n; ++i) {
        minima[0][i] = a[i];
    }
    for (int i = 1; (1<<i) <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + (1<<i) > n) break;
            minima[i][j] = min(minima[i-1][j], minima[i-1][j+(1<<(i-1))]);
        }
    }
}
inline int getmin(int a, int b) { // return minimum in [a, b]
    if (a > b) swap(a, b);
    --b;
    int len = b - a + 1;
    int k = 0;
    while ((1<<(k+1)) <= len) ++k;
    return min(minima[k][a], minima[k][b-(1<<k)+1]);
}

pair<int, int> get_lr(int p, int len) {
    pair<int, int> res;
    int l = 1, r = p;
    while (l < r) {
        int mid = l + (r - l) / 2;
        assert(mid != p);
        if (getmin(mid, p) >= len) r = mid;
        else l = mid + 1;
    }
    res.first = l;
    l = p; r = n;
    while (l < r) {
        int mid = r - (r - l) / 2;
        assert(mid != p);
        if (getmin(mid, p) >= len) l = mid;
        else r = mid - 1;
    }
    res.second = r;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        string s;
        cin >> s;
        sa.init(s);
        init();
        init_st(vector<int>(sa.lcp + 1, sa.lcp + n + 1));
        for (int i = 1; i <= n; ++i) {
            // cout << s.substr(sa.sa[i]) << ' ' << sa.sa[i] << ' ' << name(sa.lcp[i]) << endl;
            add(roots[i - 1], roots[i] = ++cnt, 0, n, sa.sa[i]);
        }
        // cout << endl;
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            --l; --r;
            int p = sa.rank[l];
            auto res = get_lr(p, r - l + 1);
            int s = res.first, t = res.second;
            // cout << s << ' ' << t << ' ' << k << endl;
            int ans = query(roots[s - 1], roots[t], 0, n, k) + 1;
            cout << (ans == n + 1 ? -1 : ans) << endl;
            // cout << name(p) << endl;
            // for (int i = 1; i <= n; ++i) {
            //     cout << name(i) << name(p) << endl;
            //     cout << name(getmin(i, p)) << endl;
            // }
            // cout << s.substr(l, r - l + 1) << endl;
            // cout << s.substr(sa.sa[l + 1]) << endl;
            // cout << endl;
        }
    }
    return 0;
}
