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
    cin >> n;
    vector<int> a(2 * n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    LL ans = LL(a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for (int i = 1; i + n - 1 < 2 * n - 1; ++i) {
        ans = min(ans, LL(a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
    }
    cout << ans << endl;
    return 0;
}
