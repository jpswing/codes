#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using LL = long long;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    LL k;
    while (cin >> n >> k) {
        vector<int> a(n);
        auto cnt = [&](LL mid) {
            LL sum = 0;
            LL res = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                j = max(j, i);
                while (j < n && sum + a[j] <= mid) {
                    sum += a[j++];
                    res += j - i;
                }
                if (j > i) sum -= a[i];
            }
            return res;
        };
        for (int i = 0; i < n; ++i) cin >> a[i];
        // cerr << name(cnt(3)) << endl;
        LL l = 0, r = 1e15;
        while (l < r) {
            LL mid = l + (r - l) / 2;
            if (cnt(mid) >= k) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}
