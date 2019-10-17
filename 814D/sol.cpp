#include <iostream>
#include <cmath>
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

const double PI = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(10);
    cout << fixed;
    int n;
    cin >> n;
    vector<tuple<int,int,int>> a;
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        a.emplace_back(x, y, r);
    }
    sort(a.begin(), a.end(), [&](tuple<int,int,int> &l, tuple<int,int,int> &r) {
        return get<2>(l) < get<2>(r);
    });
    auto in = [&](int i, int j) {
        LL x1, y1, r1, x2, y2, r2;
        tie(x1, y1, r1) = a[i];
        tie(x2, y2, r2) = a[j];
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r2 - r1) * (r2 - r1);
    };
    vector<vector<int>> g(n);    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (in(i, j)) {
                g[j].push_back(i);
                break;
            }
        }
    }
    vector<int> d(n);
    function<void(int)> dfs = [&](int u) {
        for (auto v : g[u]) {
            d[v] = d[u] + 1;
            dfs(v);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) dfs(i);
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        LL tmp = 1LL * get<2>(a[i]) * get<2>(a[i]);
        if (d[i] == 0 || d[i] % 2 == 1) ans += tmp;
        else ans -= tmp;
    }
    cout << PI * ans << endl;

    return 0;
}
