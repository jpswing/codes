#include <iostream>
#include <queue>
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

void NO() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].emplace_back(v, i);
    }
    vector<int> dp(n);
    function<void(int, int)> dfs = [&](int u, int lv) {
        if (dp[u]) return;
        for (auto e : g[u]) {
            if (e.second > lv) continue;
            dfs(e.first, lv);
            dp[u] = max(dp[e.first], dp[u]);
        }
        ++dp[u];
    };
    auto go = [&](int lv) {
        fill(dp.begin(), dp.end(), 0);
        for (int i = 0; i < n; ++i) dfs(i, lv);
        return *max_element(dp.begin(), dp.end());
    };
    int l = 0, r = m;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (go(mid) == n) r = mid;
        else l = mid + 1;
    }
    // fill(vis.begin(), vis.end(), 0);
    // dfs(start, 2);
    // cout << name(accumulate(vis.begin(), vis.end(), 0)) << endl;
    cout << (l == m ? -1 : l + 1) << endl;
    return 0;
}
