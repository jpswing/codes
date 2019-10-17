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

    // 口区
    cout.precision(4);
    cout << fixed;
    int n, s;
    while (cin >> n >> s) {
    vector<vector<double>> dp(s + 2, vector<double>(n + 2));
    // cout << name(dp[1][1]) << ' ' << name(dp[2][1]) << '\n';
    for(int i = s; i >= 0; i--) {
        for(int j = n; j >= 0; j--) {
            if(i==s&&j==n)
                continue;
            double p1=i*j*1.0/(n*s);
            double p2=(s-i)*j*1.0/(n*s);
            double p3=(n-j)*i*1.0/(n*s);
            double p4=(s-i)*(n-j)*1.0/(n*s);
            dp[i][j]=(p1*dp[i][j]+p2*dp[i+1][j]+p3*dp[i][j+1]+p4*dp[i+1][j+1]+1)/(1-p1);
        }
    }
    cout << dp[0][0] << '\n';
    }
    return 0;
}
