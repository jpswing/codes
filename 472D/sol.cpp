#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <functional>

using namespace std;

using LL = long long;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x)

void NO() {
    cout << "NO\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    int one = 0;
    vector<tuple<int,int,int>> edge;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
            one |= (g[i][j] > 0);
            if (i != j) edge.emplace_back(g[i][j], i, j);
        }
    }
    if (!one && n > 1) {
        NO();
    }
    vector<int> fa(n, -1);
    function<int(int)> find = [&](int u) { return (fa[u] < 0 ? u : (fa[u] = find(fa[u]))); };
    auto unite = [&](int u, int v) {
        int r1 = find(u), r2 = find(v);
        if (r1 == r2) return;
        if (fa[r1] < fa[r2]) fa[r2] = r1;
        else {
            if (fa[r1] == fa[r2]) --fa[r2];
            fa[r1] = r2;
        }
    };
    sort(edge.begin(), edge.end());
    vector<vector<pair<int,int>>> mst(n);
    for (int i = 0; i < edge.size(); ++i) {
        int w, u, v;
        tie(w, u, v) = edge[i];
        if (find(u) != find(v)) {
            mst[u].emplace_back(v, w);
            mst[v].emplace_back(u, w);
            unite(u, v);
        }
    }
    vector<vector<int>> dis(n, vector<int>(n, -1));
    function<void(int, int)> dfs = [&](int u, int fa) {
        dis[u][u] = 0;
        for (auto e : mst[u]) {
            int v = e.first, w = e.second;
            if (v == fa) continue;
            for (int k = 0; k < n; ++k) 
                if (dis[k][u] != -1) dis[k][v] = dis[v][k] = dis[u][k] + g[u][v]; 
            dfs(v, u);
        }
    };
    dfs(0, -1);
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << (dis == g ? "YES\n" : "NO\n"); 
    return 0;
}
