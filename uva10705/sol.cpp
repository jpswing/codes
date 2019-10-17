#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

void show2(unsigned long long v, int k) {
    for (int i = k - 1; i >= 0; --i) {
        cout << ((v>>i) & 1);
    }
    cout << endl;
}

#define NO do { cout << "Impossible\n"; return; } while(0)

void go() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    LL n;
    cin >> n;
    unsigned long long pos = 0, neg = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'p') pos += (1LL<<i);
        else neg += (1LL<<i);
    }
    if (n < 0 && neg < (-n) || n >= 0 && pos < n) NO;
    // cerr << name(pos) << name(neg) << name(n) << endl;
    unsigned long long d = (n >= 0 ? pos - n : neg - (-n));
    // cerr << name(n <= 0) << name(d <= neg) << endl;
    // cerr << name(LL(neg) + n) << endl;
    // cerr << name(d) << endl;
    unsigned long long ans = (n >= 0 ? pos : neg);
    for (int i = k - 1; i >= 0; --i) {
        if ((1LL<<i) <= d) {
            d -= (1LL<<i);
            ans ^= (1LL<<i);
        }
    }
    if (d != 0) NO;
    show2(ans, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        go();
    }
    return 0;
}
