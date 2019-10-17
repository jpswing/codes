#include <iostream>
#include <random>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int r(int s, int e) { return uniform_int_distribution<int>(s, e)(rng); }

int main() {
    // int n = r(1, 5), m = r(1, 5);
    // cout << n << ' ' << m << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << r(1, 5) << ' ';
    // }
    // cout << endl;
    cout << 30 << ' ' << 10 << endl;
    for (int i = 0; i < 30; ++i) cout << 1000000 << ' ';
    cout << endl;
    return 0;
}
