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

    cout.precision(6);
    cout << fixed;
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    // vector<vector<double>> dp(n, vector<double>(1 << n));
    vector<vector<double>> prep(n, vector<double>(1 << n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if (!(j & (1 << i))) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || !(j & (1 << k))) continue;
                prep[i][j] += a[k][i];
            }
            // cout << name(j) << name(prep[i][j]) << endl;
        }
    }
    auto eat = [&](int mask, int k) {
        int x = __builtin_popcount(mask);
        double prob = x * (x - 1) / 2;
        return prep[k][mask] / prob;
    };
    for (int i = 0; i < n; ++i) {
        vector<double> dp(1 << n);
        dp[1 << i] = 1;
        for (int j = 0; j < (1 << n); ++j) {
            if (!(j & (1 << i))) continue;
            for (int k = 0; k < n; ++k) {
                if (k == i || !(j & (1 << k))) continue;
                dp[j] += dp[j ^ (1 << k)] * eat(j, k);
            }
        }
        cout << dp[(1 << n) - 1] << ' ';
        // for (int j = 0; j < (1 << n); ++j) {
        //     cout << name(j) << name(dp[j]) << endl;
        // }
    }
    cout << endl;
    return 0;
}
