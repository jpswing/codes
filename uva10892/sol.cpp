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

int gcd(int a, int b) {
    while (b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        vector<int> facs;
        for (int i = 1; (LL)i * i <= n; ++i) {
            if (n % i != 0) continue;
            facs.push_back(i);
            if (i * i != n) facs.push_back(n / i);
        }
        int ans = 0;
        cout << facs.size() << endl;
        for (int i = 0; i < facs.size(); ++i) {
            // cout << facs[i] << ' ';
            for (int j = i + 1; j < facs.size(); ++j) 
                if (gcd(facs[i], facs[j]) == 1) ++ans;
        }
        // cout << endl;
        cout << n << ' ' << ans + 1 << '\n';
    }
    return 0;
}
