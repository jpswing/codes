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

inline LL gcd(LL a, LL b) {
    LL tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp; 
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        LL n, s1, v1, s2, v2;
        cin >> n >> s1 >> v1 >> s2 >> v2;
        LL ans = 0;
        LL lcm = s1 / gcd(s1, s2) * s2;
        LL mv = max(lcm / s1 * v1, lcm / s2 * v2);
        ans = (n / lcm - 1) * mv;
        if (s1 < s2) swap(s1, s2), swap(v1, v2);
        LL add = 0;
        n -= ans / mv * lcm;
        // cerr << n << endl;
        for (LL cur = 0; cur <= n; cur += s1) {
            LL rem = n - cur;
            add = max(add, cur / s1 * v1 + rem / s2 * v2);
            // cerr << name(cur * v1 + rem / s2 * v2) << endl;
            // cerr << name(add) << endl;
        }
        cout << "Case #" << cs << ": " << ans + add << '\n';
    }
    return 0;
}
