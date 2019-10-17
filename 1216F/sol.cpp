#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <tuple>
#include <functional>
#include <queue>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    LL ans = 0;
    string s;
    cin >> s;
    vector<int> best(n);
    int prev = -1;
    for (int i = n - 1; i >= -k; --i) {
        if (i >= 0 && s[i] == '1') prev = i;
        if (i + k < n) best[i + k] = prev;
    }
    vector<LL> dp(n + 1, INF64);
    dp[n] = 0;
    for (int i = n; i > 0; --i) {
        if (best[i - 1] != -1 && best[i - 1] - k <= i - 1) {
            LL &tmp = dp[max(0, best[i - 1] - k)];
            tmp = min(tmp, dp[i] + best[i - 1] + 1);
        }
        dp[i - 1] = min(dp[i] + i, dp[i - 1]);
    }
    cout << dp[0] << endl;
    // for (auto i : dp) cout << i << ' ';
    // cout << endl;

    return 0;
}
