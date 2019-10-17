#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 1000;
const int MAXK = 1000;
const int MAXM = 1000;

int main() {
    int t, n, k, m;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d %d", &n, &k, &m);
        static double p[MAXN], f[MAXK + 1];
        for (int i = 0; i < n; i++) scanf("%lf", &p[i]);
        std::fill(f, f + m + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                f[i] += p[j] * pow(f[i - 1], j);
            }
        }
        printf("Case #%d: %.7lf\n", i, pow(f[m], k));
    }

    return 0;
}
