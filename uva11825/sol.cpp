#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>

using namespace std;

using LL = long long;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int cs = 0;
    while (cin >> n && n) {
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            while (m--) {
                int v;
                cin >> v;
                g[i][v] = 1;
            }
        }
        vector<int> all(1<<n);
        for (int i = 0; i < (1<<n); ++i) {
            vector<int> used(n);
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i) {
                    used[j] = 1;
                    for (int k = 0; k < n; ++k) if (g[j][k]) used[k] = 1;
                }
            }
            all[i] = accumulate(used.begin(), used.end(), 0) == n;
        }
        // for (int i = 0; i < (1<<n); ++i) cerr << all[i] << ' ';
        // cerr << endl;
        vector<int> dp(1<<n);
        for (int i = 0; i < (1<<n); ++i) {
            for (int j = i; j; j = (j - 1) & i) {
                dp[i] = max(dp[i], dp[j ^ i] + all[j]);
            }
        }
        // cerr << dp[1] << endl;
        cout << "Case " << ++cs << ": " << dp[(1<<n) - 1] << '\n';
    }
    return 0;
}
