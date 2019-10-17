#include <iostream>
#include <cstring>
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
const int N = 2e5 * 30 + 10;

#define name(x) #x": " << (x) << ' '

struct Trie {
    int trie[N][3];
    int tol;
    void init() {
        memset(trie, 0, sizeof(trie));
        tol = 0;
    }
    void add(const string &s) {
        int cur = 0;
        for (auto c : s) {
            if (trie[cur][c] == 0) trie[cur][c] = ++tol;
            cur = trie[cur][c];
        }
        ++trie[cur][2];
    }
    bool remove(const string &s, int i, int cur) {
        if (i == s.size()) {
            return --trie[cur][2];
        }
        char c = s[i];
        bool res = remove(s, i + 1, trie[cur][c]);
        if (!res) trie[cur][c] = 0;
        bool have = false;
        for (int i = 0; i < 2; ++i) 
            if (trie[cur][i]) have = true;
        return have;
    }
    string get(const string &s) {
        int cur = 0;
        string res;
        for (auto c : s) {
            if (trie[cur][c ^ 1]) {
                cur = trie[cur][c ^ 1];
                res.push_back(1);
            }
            else {
                cur = trie[cur][c];
                res.push_back(0);
            }
        }
        return res;
    }
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    trie.add(string(30, 0));
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        string v;
        for (int i = 29; i >= 0; --i) {
            v.push_back(((x >> i) & 1));
        }
        if (s[0] == '+') {
            trie.add(v);
        }
        else if (s[0] == '-') {
            trie.remove(v, 0, 0);
        }
        else {
            auto res = trie.get(v);
            assert(res.size() == 30);
            int ans = 0;
            for (int i = 0; i < 30; ++i) {
                ans |= (res[i] << (30 - i - 1));
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
