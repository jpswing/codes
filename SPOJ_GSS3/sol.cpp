#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using LL = long long;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

struct node {
    LL right;
    LL left;
    LL mx;
    LL sum;
} tree[N << 2];
int a[N];

node pullup(node &res1, node &res2) {
    node ans;
    ans.left = max(res1.left, res1.sum + res2.left);
    ans.right = max(res2.right, res2.sum + res1.right);
    ans.mx = max({res1.mx, res2.mx, res1.right + res2.left});
    ans.sum = res1.sum + res2.sum;
    return ans;
}

void build(int x, int y, int k) {
    if (x == y) {
        tree[k].mx = a[x];
        tree[k].right = tree[k].left = tree[k].sum = a[x];
        return;
    }
    int h = (x + y) / 2;
    build(x, h, k << 1);
    build(h + 1, y, k << 1 | 1);
    tree[k] = pullup(tree[k << 1], tree[k << 1 | 1]);
}

void modify(int p, int k, int x, int y, int v) {
    if (x == y) {
        tree[k].mx = a[x];
        tree[k].right = tree[k].left = tree[k].sum = a[x];
        return;
    }
    int h = (x + y) / 2;
    if (p <= h) modify(p, k << 1, x, h, v);
    else modify(p, k << 1 | 1, h + 1, y, v);
    tree[k] = pullup(tree[k << 1], tree[k << 1 | 1]);
}

node query(int a, int b, int k, int x, int y) {
    if (a <= x && b >= y) {
        return tree[k];
    }
    int h = (x + y) / 2;
    node res1 = {-INF64}, res2 = {-INF64};
    if (a <= h) {
        res1 = query(a, b, k << 1, x, h);
    }
    if (b > h) {
        res2 = query(a, b, k << 1 | 1, h + 1, y);
    }
    if (res1.right == -INF64) return res2;
    if (res2.right == -INF64) return res1;

    return pullup(res1, res2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(0, n - 1, 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int cmd, x, y;
        cin >> cmd >> x >> y;
        if (cmd == 0) {
            --x;
            a[x] = y;
            modify(x, 1, 0, n - 1, y);
        }
        else {
            --x; --y;
            cout << query(x, y, 1, 0, n - 1).mx << '\n';
        }
    }
    return 0;
}
