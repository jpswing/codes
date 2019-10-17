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
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int i, int j) { return a[i] > a[j]; });
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += a[b[i]] * i + 1;
    cout << ans << endl;
    for (int i = 0; i < n; ++i) cout << b[i] + 1 << ' ';
    cout << endl;
    return 0;
}
