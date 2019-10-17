#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

const double EPS = 1e-6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(2);
    cout << fixed;
    int n; 
    double a;
    while (cin >> n >> a) {
        auto ok1 = [&](double b) {
            auto ok2 = [&](double cur) {
                double pre = a;
                int zero = 0;
                for (int i = 2; i < n; ++i) {
                    double nxt = (cur + 1) * 2 - pre;
                    pre = cur;
                    cur = nxt;
                    // cerr << cur << ' ';
                    zero |= (cur < 0);
                }
                // cerr << endl;
                return make_pair(cur > b, zero);
            };
            double l = 0, r = 1e9;
            int zero = 0;
            while (r - l > EPS) {
                double mid = l + (r - l) / 2;
                auto res = ok2(mid);
                zero = res.second;
                if (res.first) r = mid;
                else l = mid;
            }
            return zero;
        };
        double l = 0, r = 1e9;
        while (r - l > EPS) {
            double mid = l + (r - l) / 2;
            if (ok1(mid)) l = mid;
            else r = mid;
        }
        cout << (l + r) / 2 << '\n';
    }
    return 0;
}
