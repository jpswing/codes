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

    int x[7], y[7];
    vector<int> a, b;
    for (int i = 1; i <= 6; ++i) {
        cin >> x[i] >> y[i];
        a.push_back(x[i]);
        a.push_back(x[i] - 1);
        a.push_back(x[i] + 1);
        b.push_back(y[i]);
        b.push_back(y[i] - 1);
        b.push_back(y[i] + 1);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 1; i <= 6; ++i) {
        x[i] = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
        y[i] = lower_bound(b.begin(), b.end(), y[i]) - b.begin();
        // cout << x[i] << ' ' << y[i] << endl;
    }
    int g[50][50];
    auto paint = [&](int x1, int x2, int y1, int y2, int v) {
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                g[i][j] = v;
            }
        }
    };
    paint(x[1], x[2], y[1], y[2], 0);
    paint(x[3], x[4], y[3], y[4], 1);
    paint(x[5], x[6], y[5], y[6], 1);
    for (int i = x[1]; i <= x[2]; ++i) {
        for (int j = y[1]; j <= y[2]; ++j) {
            if (g[i][j] == 0) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
