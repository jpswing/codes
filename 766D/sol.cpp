#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cassert>
#include <numeric>
#include <functional>
#include <tuple>
#include <map>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        mp[s] = i;
    }
    vector<int> fa(n, -1);
    function<int(int)> find = [&](int u) { return fa[u] < 0 ? u : (fa[u] = find(fa[u])); };
    auto unite = [&](int u, int v) {
        int r1 = find(u), r2 = find(v);
        if (r1 == r2) return;
        if (fa[r1] < fa[r2]) {
            fa[r2] = r1;
            return; 
        }
        if (fa[r1] == fa[r2]) {
            --fa[r2];
        }
        fa[r1] = r2;
    };
    vector<int> ans1(m, -1);
    vector<tuple<int,int,int>> edge;
    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int c; string s1, s2;
        cin >> c >> s1 >> s2;
        --c;
        int u = mp[s1], v = mp[s2];
        edge.emplace_back(c, u, v);
        if (find(u) != find(v)) {
            unite(u, v);
            g[u].emplace_back(v, c);
            g[v].emplace_back(u, c);
            ans1[i] = 1;
        }
    }
    vector<int> vis(n);
    vector<int> d(n);
    function<void(int,int)> dfs = [&](int u, int fa) {
        if (vis[u]) return;
        vis[u] = true;
        for (auto &e : g[u]) {
            int v = e.first, w = e.second;
            if (v == fa) continue;
            d[v] = d[u] ^ w;
            dfs(v, u);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i, -1);
    }
    for (int i = 0; i < m; ++i) {
        if (ans1[i] == -1) {
            int c, u, v;
            tie(c, u, v) = edge[i];
            ans1[i] = (c == (d[u] ^ d[v]));
        }
    }
    for (auto i : ans1) cout << (i == 0 ? "NO\n" : "YES\n");
    while (q--) {
        string s1, s2;
        cin >> s1 >> s2;
        int u = mp[s1], v = mp[s2];
        if (find(u) != find(v)) cout << 3 << '\n';
        else cout << (d[u] ^ d[v]) + 1 << '\n';
    }
    return 0;
}
