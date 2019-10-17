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
const int N = 500 * 80 + 10;

#define name(x) #x": " << (x) << ' '

// vector<string> dics;
string tmp;
struct Trie {
    int trie[N][128];
    int tol;
    void init() {
        tmp.clear();
        memset(trie, 0, sizeof(trie));
        tol = 0;
    }
    void add(const string &s) {
        int cur = 0;
        for (auto c : s) {
            if (trie[cur][c] == 0) trie[cur][c] = ++tol;
            cur = trie[cur][c];
        }
    }
            
    void dfs(int cur, int d) {
        if (trie[cur][int('\\')]) {
            cout << string(d, ' ') << tmp << '\n';
            // dics.push_back(tmp);
            auto b = tmp;
            tmp.clear();
            dfs(trie[cur][int('\\')], d + 1);
            tmp = b; 
        }
        for (int i = 0; i < 128; ++i) {
            if (i == '\\') continue;
            if (trie[cur][i]) {
                tmp.push_back(char(i));
                dfs(trie[cur][i], d);
                tmp.pop_back();
            }
        }
    }
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        trie.init();
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (s.back() != '\\') trie.add(s + '\\');
            else trie.add(s);
        }
        trie.dfs(0, 0);
        cout << '\n';
    }    

    return 0;
}
