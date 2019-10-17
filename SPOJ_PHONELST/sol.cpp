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
const int N = 10000 * 10 + 10;

#define name(x) #x": " << (x) << ' '

struct Trie {
    int trie[N][11];
    int tol;
    vector<int> ep;
    void init() {
        memset(trie, 0, sizeof(trie));
        ep.clear();
        tol = 0;
    }
    void add(const string &s) {
        int cur = 0;
        for (auto c : s) {
            c = c - '0';
            if (trie[cur][c] == 0) trie[cur][c] = ++tol;
            cur = trie[cur][c];
        }
        trie[cur][10] = 1;
        ep.push_back(cur);
    }
            
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        trie.init();
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            trie.add(s);
        }
        for (auto p : trie.ep) {
            for (int i = 0; i < 10; ++i) if (trie.trie[p][i] != 0) {
                cout << "NO\n";
                goto nxt;
            }
        }
        cout << "YES\n";
        nxt:;
    }
    return 0;
}
