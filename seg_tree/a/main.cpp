#include <cstdio>
#include <algorithm>
#include <vector>

long long sum(const std::vector<long long> &, int, int);

int main() {
    FILE *rFile, *wFile;
    rFile = fopen("sum0.in", "r");
    wFile = fopen("sum0.out", "w");
    long long ans = 0;

    long long n, x, y, a0, a_mod = 1 << 16;
    fscanf(rFile, "%lld%lld%lld%lld", &n, &x, &y, &a0);

    int m, z, t, b0, b_mod = 1 << 30;
    fscanf(rFile, "%lld%lld%lld%lld", &m, &z, &t, &b0);

    std::vector<long long> a(n), d(n);
    std::vector<long long> b((m << 1)), c((m << 1));

    if (m != 0) {

        b[0] = b0;
        c[0] = b[0] % n;

        for (int i = 1; i < b.size(); i++) {
            b[i] = (z * b[i - 1] + t) % b_mod;
            if (b[i] < 0) {
                b[i] += b_mod;
            }
            c[i] = b[i] % n;
        }

        a[0] = a0 ;
        d[0] = a0;

        for (int i = 1; i < n; ++i) {
            d[i] = (x * d[i - 1] + y) % a_mod;
            a[i] = a[i - 1] + d[i];
        }


        for (int i = 0; i < m; i++) {
            int l = std::min(c[i << 1], c[(i << 1) + 1]);
            int r = std::max(c[i << 1], c[(i << 1) + 1]);
            long long p = a[r] - a[l];
            ans += p + d[l];
        }
    }

    fprintf(wFile, "%lld", ans);
    return 0;
}

