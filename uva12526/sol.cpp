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
const int N = 1e5 * 80 + 10;

#define name(x) #x": " << (x) << ' '

struct Trie {
    int trie[N][27];
    int tol;
    void init() {
        memset(trie, 0, sizeof(trie));
        tol = 0;
    }
    void add(const string &s) {
        int cur = 0;
        for (auto c : s) {
            c = c - 'a';
            if (trie[cur][c] == 0) trie[cur][c] = ++tol;
            cur = trie[cur][c];
        }
        trie[cur][26] = 1;
    }
    int get(const string &s) {
        int cur = 0;
        int ans = 0;
        bool first = true;
        for (auto c : s) {
            c = c - 'a';
            int cnt = 0;
            for (int i = 0; i < 27; ++i) if (trie[cur][i] != 0) ++cnt;
            if (first) {
                ++ans;
                first = false;
            }
            else if (cnt > 1) ++ans;
            // cout << char(c + 'a') << name(cnt) << endl;
            cur = trie[cur][c];
        }
        return ans;
    } 

            
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(2);
    cout << fixed;
    int n;
    while (cin >> n) {
        trie.init();
        vector<string> words;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            trie.add(s);
            words.push_back(s);
        }
        int ans = 0;
        for (auto &s : words) {
            ans += trie.get(s);
            // cout << name(s) << name(ans) << '\n';
        }
        cout << 1.0 * ans / n << '\n';
    }
    return 0;
}
