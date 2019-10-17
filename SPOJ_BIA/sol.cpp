#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
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
    while (cin >> n >> m) {
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
        }
        vector<int> vis(n);
        int del = -1;
        function<void(int)> dfs = [&](int u) {
            if (u == del || vis[u]) return;
            vis[u] = true;
            for (auto v : g[u]) {
                dfs(v);
            }
        };
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            fill(vis.begin(), vis.end(), 0);
            del = i;
            dfs(0);
            if (count(vis.begin(), vis.end(), true) < n - 1) ans.push_back(i + 1);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
