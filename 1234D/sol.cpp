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

template <typename T>
T debug(T x) {
    cout << x << endl;
    return x;
}
#define name(x) #x": " << (x) << ' '
#define debug(x) (cout << #x": ", dbg(x))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int q;
    cin >> q;
    set<int> st[26];
    for (int i = 0; i < s.size(); ++i) {
        st[s[i] - 'a'].insert(i);
    }
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int pos; char c;
            cin >> pos >> c;
            --pos; st[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            st[c - 'a'].insert(pos);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int ans = 0;
            for (int i = 0; i < 26; ++i) {
                // cout << name(i) << name(st[i].size()) << endl;
                // cout << *st[i].upper_bound(r) << *st[i].lower_bound(l) << endl;
                // cout << name(i);
                // for (auto p : st[i]) cout << p << ' ';
                // cout << endl;
                ans += (st[i].upper_bound(r) != st[i].lower_bound(l));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
