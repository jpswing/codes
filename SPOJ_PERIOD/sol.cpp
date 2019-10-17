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

template<typename T>
vector<int> kmp(const T &a) { // fail[i]是为a[0...i]的后缀的最长前缀
    int n = a.size();
    vector<int> fail(n);
    fail[0] = -1;
    for (int i = 1; i < n; ++i) {
        fail[i] = fail[i - 1];
        while (~fail[i] && a[fail[i] + 1] != a[i]) {
            fail[i] = fail[fail[i]];
        }
        if (a[fail[i] + 1] == a[i]) {
            ++fail[i];
        }
    }
    return fail;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        if (cs != 1) cout << '\n';
        cout << "Test case #" << cs << '\n';
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto fail = kmp(s);
        for (int i = 0; i < fail.size(); ++i) {
            int len = i - fail[i];
            if (fail[i] != -1 && (i + 1) % len == 0) {
                cout << i + 1 << ' ' << (i + 1) / len << '\n';
            }
        }
    }
    return 0;
}
