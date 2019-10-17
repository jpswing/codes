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

#define name(x) #x": " << (x) << ' '

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s[2];
        for (int i = 0; i < 2; ++i) cin >> s[i];
        int i = 0, j = 0, d = 1; // flow in
        // int op[3] = {2, 1, 0};
        tuple<int,int,int> straight[3] = {make_tuple(1, 0, 0), make_tuple(0, 1, 1), make_tuple(-1, 0, 2)};
        tuple<int,int,int> bend[2][3] = {make_tuple(0, 1, 1), make_tuple(1, 0, 0), make_tuple(0, 1, 1), make_tuple(0, 1, 1), make_tuple(-1, 0, 2), make_tuple(0, 1, 1)};
        while (true) {
            if (i == -1 || i == 2 || j == n) break;
            int dx, dy, nd;
            if (s[i][j] <= '2') {
                tie(dx, dy, nd) = straight[d];
            }
            else {
                tie(dx, dy, nd) = bend[i][d];
            }
            i += dx; j += dy; d = nd;
            // cout << i << ' ' << j << endl;
        }
        // cout << i << ' ' << j << endl;
        if (i != 1 || j != n) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
