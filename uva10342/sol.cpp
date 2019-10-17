#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <functional>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int cs = 0;
    while (cin >> n >> m) {
        cout << "Set #" << ++cs << '\n';
        vector<vector<pair<int,int>>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        int q;
        cin >> q;
        while (q--) {
            int s, t;
            cin >> s >> t;
            vector<int> d(n, INF), d2(n, INF);
            d[s] = 0;
            priority_queue<pair<int,int>> q;
            q.emplace(0, s);
            // vector<int> vis(n);
            while (!q.empty()) {
                int u = q.top().second, c = -q.top().first; q.pop();
                // if (vis[u]) continue;
                // cout << name(u) << ' ';
                if (c > d2[u]) continue;
                // vis[u] = true;
                for (auto &e : g[u]) {
                    int v = e.first, w = e.second;
                    if (d[u] + w < d[v]) {
                        d2[v] = d[v];
                        d[v] = d[u] + w;
                        q.emplace(-d[v], v);
                    }
                    else if (d[u] + w > d[v] && d[u] + w < d2[v]) {
                        d2[v] = d[u] + w;
                        q.emplace(-d2[v], v);
                    }
                    if (d2[u] + w > d[v] && d2[u] + w < d2[v]) {
                        d2[v] = d2[u] + w;
                        q.emplace(-d2[v], v);
                    }
                }
            }
            if (d2[t] == INF) cout << "?\n";
            else cout << d2[t] << '\n';
        }
    }
    return 0;
}
