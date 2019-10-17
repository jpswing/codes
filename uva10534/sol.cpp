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

    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> ls(n), gt(n);
        vector<int> dp;
        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            if (pos == dp.size()) dp.push_back(a[i]);
            else dp[pos] = a[i];
            ls[i] = pos;
        }
        dp.clear();
        for (int i = n - 1; i >= 0; --i) {
            int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            if (pos == dp.size()) dp.push_back(a[i]);
            else dp[pos] = a[i];
            gt[i] = pos;
        }
        // for (int i = 0; i < n; ++i) cout << ls[i] << ' ';
        // cout << endl;
        // for (int i = 0; i < n; ++i) cout << gt[i] << ' ';
        // cout << endl;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, 2 * (min(ls[i], gt[i]) + 1) - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
