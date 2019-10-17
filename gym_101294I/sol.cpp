#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <queue>
#include <map>
#include <set>
#include <cstring>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

int dp[33][33][33];

void min_s(int &v, int w) {
    v = min(v, w);
}
int a[33];
int n, m;

void print(int i, int j, int k) {
    if (i == 1) {
        cout << j << ' ';
        return;
    }
    int add = 0;
    for (int x = 0, tmp = 0; x < j; ++x) {
        add = add + tmp + a[k - x];
        tmp += a[k - x];
    }
    for (int y = 1; y <= n; ++y) {
        if (dp[i - 1][y][k - j] + add == dp[i][j][k]) {
            print(i - 1, y, k - j);
            break;
        }
    }
    cout << j << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1][0] = a[0];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k < n - 1; ++k) {
                min_s(dp[i][j + 1][k + 1], dp[i][j][k] + (j + 1) * a[k + 1]);
                min_s(dp[i + 1][1][k + 1], dp[i][j][k] + a[k + 1]);
            }
        }
    }
    int mv = INF;
    for (int j = 1; j <= n; ++j) {
        min_s(mv, dp[min(n, m)][j][n - 1]);
    }
    for (int j = 1; j <= n; ++j) {
        if (mv == dp[min(n, m)][j][n - 1]) {
            print(min(n, m), j, n - 1);
            break;
        }
    }
    for (int i = n; i < m; ++i) cout << 0 << ' ';
    // cerr << name(dp[1][2][1]) << name(dp[2][1][1]) << endl;
    // cout << mv << '\n';
    return 0;
}
