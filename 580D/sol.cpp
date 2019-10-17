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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int>> g(n, vector<int>(n));
    while (k--) {
        int x, y, c;
        cin >> x >> y >> c;
        --x; --y;
        g[x][y] = c;
    }
    vector<vector<LL>> dp(1 << n, vector<LL>(n));
    LL ans = 0;
    for (int i = 0; i < n; ++i) dp[1 << i][i] = a[i];
    for (int i = 1; i < (1 << n); ++i) {
        if (__builtin_popcount(i) > m) continue;
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) continue;
            int mask = i ^ (1 << j);
            for (int k = 0; k < n; ++k) {
                if (!(mask & (1 << k))) continue;
                dp[i][j] = max(dp[i][j], dp[mask][k] + g[k][j] + a[j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
