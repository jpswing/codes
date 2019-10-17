#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <tuple>

using namespace std;

using LL = long long;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

void dij(int s, vector<vector<pair<int,int>>> &g, vector<LL> &d) {
    priority_queue<pair<LL,int>> q;
    q.emplace(0, s);
    d[s] = 0;
    vector<int> vis(g.size());
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto &e : g[u]) {
            int v = e.first, w = e.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.emplace(-d[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m, s, t, p;
        cin >> n >> m >> s >> t >> p;
        --s; --t;
        vector<vector<pair<int,int>>> g(n);
        vector<vector<pair<int,int>>> rev(n);
        vector<tuple<int,int,int>> edge;
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            --u; --v;
            g[u].emplace_back(v, c);
            rev[v].emplace_back(u, c);
            edge.emplace_back(u, v, c);
        }
        if (s == t) {
            cout << "0\n";
            continue;
        }
        vector<LL> from(n, INF64), to(n, INF64);
        dij(s, g, from); dij(t, rev, to);
        int ans = -1;
        for (auto &e : edge) {
            int u, v, w;
            tie(u, v, w) = e;
            if (from[u] + to[v] + w <= p) {
                cerr << name(u) << name(from[u]) << name(v) << name(to[v]) << endl;
                ans = max(ans, w);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
