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
const int MOD = 1e9 + 7;

#define name(x) #x": " << (x) << ' '

template<typename T>
set<int> kmp(const T &a) { // fail[i]是为a[0...i]的后缀的最长前缀
    int n = a.size();
    vector<int> fail(n);
    fail[0] = -1;
    for (int i = 1; i < n; ++i) {
        fail[i] = fail[i - 1];
        while (~fail[i] && a[fail[i] + 1] != a[i]) {
            fail[i] = fail[fail[i]];
        }
        if (a[fail[i] + 1] == a[i]) {
            ++fail[i];
        }
    }
    set<int> ret;
    for (int i = fail.back(); i != -1; i = fail[i]) {
        ret.insert(i);
        // cerr << name(i) << endl;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string p;
    cin >> p;
    int len = p.size();
    auto fail = kmp(p);
    int cnt = 0;
    int lasty = -INF;
    for (int i = 0; i < m; ++i) {
        int y;
        cin >> y;
        if (y - lasty + 1 <= len) {
            if (!fail.count(lasty + len - y - 1)) {
                cout << 0 << '\n';
                return 0;
            }
        }
        else {
            if (lasty != -INF) cnt += y - (lasty + len);
            else cnt += y - 1;
        }
        lasty = y;
        // cout << name(i) << name(cnt) << name(lasty) << endl;
    }
    if (lasty != -INF) cnt += n - (lasty + len - 1);
    else cnt = n;
    LL ans = 1;
    for (int i = 0; i < cnt; ++i) {
        ans = ans * 26 % MOD;
    }
    cout << ans << '\n';
    return 0;
}
