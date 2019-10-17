#include <iostream>
#include <cmath>
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

char g[300][300];
pair<int,int> a[3];
int b[3];

int n;

pair<int,int> find0() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == 0) return {i, j};
        }
    }
    return {-1, -1};
}

bool paint(pair<int,int> p, int w, int h, char c) {
    int x = p.first, y = p.second;
    if (n - y < w || n - x < h) return false;
    if (c != 0) {
        for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                if (g[x + j][y + i] != 0) return false;
            }
        }
    }
    else if (g[x][y] == 0) return true;
    for (int j = 0; j < h; ++j) {
        for (int i = 0; i < w; ++i) {
            g[x + j][y + i] = c;
        }
    }
    return true;
}

bool dfs(int i) {
    if (i == 3) return true;
    int x = a[b[i]].first, y = a[b[i]].second;
    auto res = find0();
    assert(res.first != -1);
    if (paint(res, x, y, b[i] + 'A') && dfs(i + 1)) return true;
    paint(res, x, y, 0);
    if (paint(res, y, x, b[i] + 'A') && dfs(i + 1)) return true;
    paint(res, y, x, 0);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].first * a[i].second; 
        b[i] = i;
    }
    n = sqrt(sum);
    if (abs(n - sqrt(sum)) > 1e-8) {
        cout << -1 << endl;
        return 0;
    }
    // cout << name(n) << endl;
    do {
        if (dfs(0)) {
            cout << n << '\n';
            for (int i = 0; i < n; ++i) cout << g[i] << endl;
            return 0;
        }
    } while (next_permutation(b, b + 3));
    cout << -1 << endl;
    return 0;
}
