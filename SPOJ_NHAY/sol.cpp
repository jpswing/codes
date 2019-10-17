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
    vector<int> res;
    for (int i = 0, j = 0; i < s.size(); ++i) {
        while (s[i] != p[j] && j > 0) j = fail[j - 1] + (fail[j - 1] != j - 1);
        if (s[i] == p[j]) {
            if (++j == p.size()) {
                res.push_back(i - p.size() + 2);
                j = fail[j - 1] + (fail[j - 1] != j - 1);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string tmp;
    while (getline(cin, tmp)) {
        n = stoi(tmp);
        string t, s;
        getline(cin, t);
        getline(cin, s);
        auto ans = KMP(s, t);
        for (auto i : ans) cout << i - 1 << '\n';
        if (ans.empty()) cout << '\n';
    }
    return 0;
}
