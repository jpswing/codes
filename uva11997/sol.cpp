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

    int k;
    while (cin >> k) {
        vector<vector<int>> a(k, vector<int>(k));
        vector<int> x;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) cin >> a[i][j];
            sort(a[i].begin(), a[i].end());
        }
        x = a[0];
        for (int i = 1; i < k; ++i) {
            auto &y = a[i];
            auto cmp = [&](pair<int,int> l, pair<int,int> r) {
                return x[l.first] + y[l.second] > x[r.first] + y[r.second];
            };
            priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
            vector<int> new_x(k);
            for (int i = 0; i < k; ++i) q.emplace(i, 0);
            for (int i = 0; i < k; ++i) {
                int r = q.top().first, c = q.top().second;
                new_x[i] = x[r] + y[c]; 
                q.pop();
                q.emplace(r, c + 1);
            }
            swap(new_x, x);
        }
        for (int i = 0; i < k; ++i) {
            cout << x[i] << " \n"[i == k - 1];
        }

    }
    return 0;
}
