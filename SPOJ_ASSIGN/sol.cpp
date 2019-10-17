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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cin >> g[i][j];
        }
        vector<LL> dp(1 << n);
        dp[0] = 1;
        for (int k = 0; k < n; ++k) {
            for (int s = (1 << k) - 1; s < (1 << n); ) {
                for (int i = 0; i < n; ++i) {
                    if (!(s & (1 << i)) && g[k][i]) {
                        dp[s | (1 << i)] += dp[s];
                    }
                }

                if (s == 0) break;
                int x = s & -s, y = s + x;
                int t = s & ~y;
                s = ((t / x) >> 1) | y;
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }    
    return 0;
}
