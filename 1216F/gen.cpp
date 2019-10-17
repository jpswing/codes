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
#include <random>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int r(int s, int e) { return uniform_int_distribution<int>(s, e)(rng); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = r(1, 20), k = r(1, 22);
    cout << n << ' ' << k << endl;
    for (int i = 0; i < n; ++i) {
        cout << r(0, 1);
    }
    cout << endl;
    return 0;
}
