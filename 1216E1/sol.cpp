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

    vector<LL> dp1(10), dp2(10);
    auto get10 = [](int v) {
        LL ans = 1;
        while (v--) ans *= 10;
        return ans;
    };
    for (int i = 1; i < 10; ++i) {
        LL tmp = get10(i) - get10(i - 1);
        dp1[i] = dp1[i - 1] + i * tmp;
        dp2[i] = dp2[i - 1] + dp1[i - 1] * tmp + tmp * i + tmp * (tmp - 1) * i / 2;
    }
    // for (int i = 0; i < 10; ++i) cout << name(dp1[i]) << name(dp2[i]) << endl;
    int q;
    cin >> q;
    while (q--) {
        LL k;
        cin >> k;
        // cout << name(k) << endl;
        // auto get_num = [](int v) {
        //     int ans = 0;
        //     do {
        //         ++ans;
        //     } while (v /= 10);
        //     return ans;
        // };
        int dig = 0;
        for (; ; ++dig) if (dp2[dig] >= k) break;
        // cout << name(dp2[dig]) << name(k) << name(dig) << endl;
        int l = 1, r = 1e9;
        LL val = -1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // int num = get_num(mid);
            LL tmp = mid - get10(dig - 1) + 1;
            val = dp2[dig - 1] + dp1[dig - 1] * tmp + tmp * dig + tmp * (tmp - 1) * dig / 2;
            if (val >= k) r = mid;
            else l = mid + 1;
        }
        // cout << name(l) << endl;
        LL tmp = l - 1 - get10(dig - 1) + 1;
        val = dp2[dig - 1] + dp1[dig - 1] * tmp + tmp * dig + tmp * (tmp - 1) * dig / 2;
        // cout << name(val) << endl;
        k -= val;
        for (dig = 0; ; ++dig) if (dp1[dig] >= k) break;
        // cout << name(dig) << endl;
        k -= dp1[dig - 1];
        l = get10(dig - 1), r = get10(dig) - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if ((mid - get10(dig - 1) + 1) * dig >= k) r = mid;
            else l = mid + 1;
        }
        k -= ((l - 1) - get10(dig - 1) + 1) * dig;
        // cout << name(l) << endl;
        string s = to_string(l);
        cout << s[k - 1] << '\n';
    }
    return 0;
}
