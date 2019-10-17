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

LL __gcd(LL a, LL b) {
    while (b) {
        LL tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

LL lcm(LL a, LL b) {
    return a / __gcd(a, b) * b;
}

pair<LL,LL> red(pair<LL,LL> a) {
    LL g = __gcd(a.first, a.second);
    a.first /= g; a.second /= g;
    return a;
}

pair<LL,LL> operator+(pair<LL,LL> a, pair<LL,LL> b) {
    LL den = lcm(a.second, b.second);
    LL num = a.first * (den / a.second) + b.first * (den / b.second);
    return red({num, den});
}
pair<LL,LL> operator*(pair<LL,LL> a, pair<LL,LL> b) {
    LL den = a.second * b.second, num = a.first * b.first;
    return red({num, den});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    while (cin >> n >> x && n) {
        vector<vector<pair<LL,LL>>> dp(n + 1, vector<pair<LL,LL>>(150 + 1, {0, 1}));
        dp[0][0] = {1, 1};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 150; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    if (j < k) continue;
                    dp[i][j] = dp[i][j] + dp[i - 1][j - k] * make_pair(1, 6);
                }
            }
        }
        pair<LL,LL> ans = {0, 1};
        for (int i = x; i <= 150; ++i) ans = ans + dp[n][i];
        if (ans.second == 1) cout << ans.first << '\n';
        else cout << ans.first << '/' << ans.second << '\n';
    }
    return 0;
}
