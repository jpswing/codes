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

    cout.precision(10);
    cout << fixed;

    int sy, a, b;
    cin >> sy >> a >> b;
    int n;
    cin >> n;
    vector<pair<int,int>> segs(n);
    vector<LL> pre1(n), pre2(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i].first >> segs[i].second;
        int tmp = segs[i].first - segs[i].second;
        pre1[i] = (i == 0 ? 0 : pre1[i - 1]) + tmp;
        pre2[i] = (i == 0 ? 0 : pre2[i - 1]) - tmp;
    }
    auto get_range = [](const vector<LL> &pre, int l, int r) {
        if (l > r) return 0LL;
        return pre[r] - (l == 0 ? 0 : pre[l - 1]);
    };
    auto fit = [&](double x) {
        if (x > b) x = b;
        else if (x < a) x = a;
        return x;
    };
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        auto f = [&](LL x2) {
            return 1.0 * (sy * (x - x2) + y * x2) / y;
        };
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = r - (r - l) / 2;
            int x2 = segs[mid].first;
            if (f(x2) < a) l = mid;
            else r = mid - 1;
        }
        int t1 = l + 1;
        double ans = 0;
        ans += fit(f(segs[l].second)) - fit(f(segs[l].first)); // max(1.0 * a, min(1.0 * b, f(segs[l].second))) - max(1.0 * a, f(segs[l].first));
        // cout << name(f(segs[l].first)) << name(f(segs[l].second)) << endl;
        // cout << name(ans) << endl;
        l = l + 1; r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int x2 = segs[mid].second;
            if (f(x2) > b) r = mid;
            else l = mid + 1;
        }
        int t2 = l - 1;
        if (l < n) ans += fit(f(segs[l].second)) - fit(f(segs[l].first)); // min(1.0 * b, f(segs[l].second)) - min(1.0 * b, max(1.0 * a, f(segs[l].first)));
        // cout << name(ans) << endl;
        ans += 1.0 * sy * get_range(pre1, t1, t2) / y + get_range(pre2, t1, t2);
        cout << ans << '\n';
        // for (int i = 0; i < n; ++i) {
        //     cout << f(segs[i].first) << ' ' << f(segs[i].second) << endl;
        // }
        // cout << 1.0 * sy * t1 / y + t2 << '\n';
    }
    return 0;
}
