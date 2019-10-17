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
    set<int> vis;
    queue<int> q;
    // for (int i = 0; i < k; ++i) q.push(-1);
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        if (vis.count(id)) continue;
        else {
            q.push(id);
            if (q.size() > k) {
                int last = q.front();
                q.pop();
                vis.erase(last);
            }
            vis.insert(id);
        }
    }
    cout << q.size() << endl;
    function<void()> print = [&]() {
        if (q.empty()) return;
        int last = q.front();
        q.pop();
        print();
        cout << last << ' ';
    };
    print();
    cout << endl;
    return 0;
}
