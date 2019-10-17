#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout.precision(2);
    cout << fixed;
    double a, b;
    int s, m, n;
    while (cin >> a >> b >> s >> m >> n && s) {
        double w = a * m, h = b * n;
        double dis = sqrt(w * w + h * h);
        cout << atan2(h, w) * 180 / PI << ' ' << dis / s << '\n';
    }
    return 0;
}

