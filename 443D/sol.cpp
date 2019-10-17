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
const int N = 1e2 + 10;

#define name(x) #x": " << (x) << ' '

pair<double,double> dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(10);
    cout << fixed;
    int n;
    cin >> n;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    double ans = 0;
    dp[0] = {1, 0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i].first = max(dp[i].first, dp[j].first * (1 - a[i]));
            dp[i].second = max(dp[i].second, dp[j].first * a[i] + dp[j].second * (1 - a[i]));
        }
        ans = max(ans, dp[i].second);
            // double new_min_no = min_no * (1 - a[j]);
            // double new_max_no = max_no * (1 - a[j]);
            // double new_min_yes = min_no * a[j];
            // double new_max_yes = max_no * a[j];
    }
    for (int i = 0; i <= n; ++i) {
        cout << dp[i].first << ' ' << dp[i].second << '\n';
    }
    cout << ans << '\n';
    return 0;
}
