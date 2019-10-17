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

struct line {
    int x1, y1, x2, y2;
    int min_y() {
        return min(y1, y2);
    }
    int which_x() {
        if (y1 < y2) return x1;
        return x2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<line> lines(m);
        for (int i = 0; i < m; ++i) {
            auto &l = lines[i];
            cin >> l.x1 >> l.y1 >> l.x2 >> l.y2;
            if (l.x1 > l.x2) {
                swap(l.x1, l.x2);
                swap(l.y1, l.y2);
            }
        }
        int n;
        cin >> n;
        auto inrange = [](int x, int l, int r) {
            return x >= l && x <= r;
        };
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            while (true) {
                double max_y = -1;
                int nxt_x = -1, nxt_y = -1;
                for (auto &line : lines) {
                    int y1 = line.y1, y2 = line.y2, x1 = line.x1, x2 = line.x2;
                    if (inrange(x, x1, x2)) {
                        double ty;
                        ty = y1 + (y2 - y1) * 1.0 * (x - x1) / (x2 - x1);
                        if (ty < y && ty > max_y) {
                            max_y = ty;
                            nxt_x = line.which_x();
                            nxt_y = line.min_y();
                        }
                    }
                }
                if (nxt_x == -1) {
                    cout << x << '\n';
                    break;
                }
                x = nxt_x; y = nxt_y;
            }

        }
        if (t) cout << '\n';

    }
    return 0;
}
