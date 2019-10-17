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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(10);
    cout << fixed;
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (b == 0) {
            cout << 1 << '\n';
            continue;
        }
        if (a == 0) {
            cout << 0.5 << '\n';
            continue;
        }
        if (a >= 4 * b) {
            cout << (1 - 2.0 * b * b / (2.0 * a * b)) << '\n';
        }
        else {
            double e = 4 * b - a;
            cout << (1 - (2.0 * b * b - e * e / 4.0 / 2) / (2.0 * a * b)) << '\n';
        }
    }
    return 0;
}
