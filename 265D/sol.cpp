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
const int N = 1e5 + 10;

#define name(x) #x": " << (x) << ' '

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> divs(N);
    for (int i = 2; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
    divs[1].push_back(1);
    for (int i = 1; i < 10; ++i) {
        cout << i << ": ";
        for (auto v : divs[i]) cout << v << ' ';
        cout << endl;
    }
    vector<int> dp(N);
    vector<int> mx(N);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (auto v : divs[x]) {
            dp[x] = max(mx[v] + 1, dp[x]);
        }
        for (auto v : divs[x]) {
            mx[v] = max(mx[v], dp[x]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[a[i]]);
    }
    cout << ans << endl;
    return 0;
}
