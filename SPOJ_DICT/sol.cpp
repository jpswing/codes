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
const int N = 25000*20 + 10;

#define name(x) #x": " << (x) << ' '

struct Trie {
    int trie[N][27];
    int tol;
    vector<string> ans;
    void add(const string &s) {
        int cur = 0;
        for (auto c : s) {
            c = c - 'a';
            if (trie[cur][c] == 0) trie[cur][c] = ++tol;
            cur = trie[cur][c];
        }
        trie[cur][26] = 1;
    }
    int where(const string &s) {
        int cur = 0;
        for (auto c : s) {
            c = c - 'a';
            if (trie[cur][c] == 0) return -1;
            cur = trie[cur][c];
        }
        return cur;
    }
            
    void get(int cur, string &s) {
        for (int i = 0; i < 26; ++i) {
            int nxt = trie[cur][i];
            if (nxt > 0) {
                s += char(i + 'a');
                if (trie[nxt][26]) ans.push_back(s);
                get(nxt, s);
                s.pop_back();
            }
        }
    }
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        trie.add(s);
    }
    int k;
    cin >> k;
    for (int cs = 1; cs <= k; ++cs) {
        cout << "Case #" << cs << ":\n";
        trie.ans.clear();
        string s;
        cin >> s;
        int cur = trie.where(s);
        if (cur == -1) {
            cout << "No match.\n";
            continue;
        }
        trie.get(cur, s);
        if (trie.ans.empty()) cout << "No match.\n";
        else for (auto &s : trie.ans) cout << s << '\n';
    }
    return 0;
}
