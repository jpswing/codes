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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        vector<int> fa(150, -1);
        function<int(int)> find = [&](int u) { return (fa[u] < 0 ? u : (fa[u] = find(fa[u]))); };
        auto unite = [&](int u, int v) {
            int r1 = find(u), r2 = find(v);
            if (r1 == r2) return;
            fa[r1] = r2;
        };
        int ans = 1;
        while (m--) {
            char u, v;
            cin >> u >> v;
            if (find(u) == find(v)) ++ans;
            else {
                unite(u, v);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
