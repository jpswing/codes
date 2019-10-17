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

template<typename T>
vector<int> kmp(const T &a) { // fail[i]是为a[0...i]的后缀的最长前缀
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
    return fail;
}
vector<int> KMP(const string &s, const string &p) {
    auto &&fail = kmp(p);
    vector<int> res(p.size());
    int i, j;
    for (i = 0, j = 0; i < s.size(); ++i) {
        while (s[i] != p[j] && j > 0) {
            // cout << 1 << ' ' << name(i) << name(j) << endl;
            // ++res[j - 1];
            j = fail[j - 1] + (fail[j - 1] != j - 1);
        }
        if (s[i] == p[j]) {
            ++res[j];
            if (++j == p.size()) {
                // cout << 2 << ' ' << name(i) << name(j) << endl;
                // res.push_back(i - p.size() + 2);
                // ++res[j - 1];
                j = fail[j - 1] + (fail[j - 1] != j - 1);
            }
        }
    }
    // if (j > 0) ++res[j - 1];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    auto fail = kmp(s);
    // for (auto i : fail) cout << i << ' ';
    // cout << endl;
    vector<int> pos;
    for (int i = fail.back(); ~i; i = fail[i]) {
        pos.push_back(i);
    }
    cout << pos.size() + 1 << '\n';
    if (fail.back() != -1) {
        string p = s.substr(s.size() - fail.back() - 1);
        auto res = KMP(s, p);
        // cout << "res: ";
        // for (auto i : res) cout << i << ' ';
        // cout << endl;
        vector<int> ans(res);
        for (int i = res.size() - 1; i >= 0; --i) {
            if (fail[i] != -1) ans[fail[i]] += ans[i];
            // ans[i] = (i + 1 == ans.size() ? 0 : ans[i + 1]) + res[i];
        }
        // cout << "ans: ";
        // for (auto i : ans) cout << i << ' ';
        // cout << endl;
        for (int i = pos.size() - 1; i >= 0; --i) {
            cout << pos[i] + 1 << ' ' << ans[pos[i]] << '\n';
        }
    }
    cout << s.size() << ' ' << 1 << '\n';
    return 0;
}
