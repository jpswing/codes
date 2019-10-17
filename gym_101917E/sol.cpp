#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <set>
#include <map>
#include <tuple>
#include <functional>
#include <cmath>

using namespace std;

using LL = long long;
const LL INF = 0x3f3f3f3f;
const LL INF64 = 0x3f3f3f3f3f3f3f3f;
const int N = 5e4 + 10;

#define name(x) #x": " << (x) << ' '

const double PI = acos(-1);

vector<double> rotate(double x, double y, double deg) {
    deg = deg * PI / 180;
    double s = sin(deg);
    double c = cos(deg);
    return {x * c - y * s, x * s + y * c};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(10);
    cout << fixed;
    int a, w, h, n;
    cin >> a >> w >> h >> n;
    vector<vector<double>> p;
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        p.emplace_back(rotate(x, y, a));
    }
    for (int i = 0; i < 2; ++i) {
        double off = (*min_element(p.begin(), p.end(), [&](const vector<double> &l, const vector<double> &r) { return l[i] < r[i]; }))[i];
        // cerr << name(off) << endl;
        for (auto &x : p) x[i] -= off;
        double frac = 1.0 * (i == 0 ? w : h) / (*max_element(p.begin(), p.end(), [&](const vector<double> &l, const vector<double> &r) { return l[i] < r[i]; }))[i];
        for (auto &x : p) x[i] *= frac;
    }
    for (auto &i : p) cout << i[0] << ' ' << i[1] << '\n';
    return 0;
}
