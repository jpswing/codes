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

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<long long> dp(n + 1);
	multiset<long long> mins, vals;
	mins.insert(0);
	vector<vector<long long>> del(n);
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = i + 1 +  dp[i + 1];
		if (i + k + 2 <= n) mins.erase(mins.find(dp[i + k + 2]));
		for (auto it : del[i]) vals.erase(vals.find(it));
		if (!vals.empty()) dp[i] = min(dp[i], *vals.begin());
		if (s[i] == '1') {
			long long val = (mins.empty() ? 0 : *mins.begin()) + i + 1;
			dp[i] = min(dp[i], val);
			vals.insert(val);
			if (i - k - 1 >= 0) del[i - k - 1].push_back(val);
		}
		mins.insert(dp[i]);
	}

	cout << dp[0] << endl;

    return 0;
}
