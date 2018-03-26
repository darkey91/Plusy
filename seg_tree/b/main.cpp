#include <cmath>
#include <cstdio>
#include <vector>

long long get(const std::vector <long long> &, int, int , int, int, int);
void up(std::vector <long long> &, int, long long, int);

int main() {
    FILE *rFile, *wFile;
    rFile = fopen("rsq.in", "r");
    wFile = fopen("rsq.out", "w");

    int n;
    fscanf(rFile, "%d", &n);

    int p = 1;
    while (p < n) {
        p <<= 1;
    }

    std::vector<long long> t((p << 1) - 1);

    for (int i = p - 1; i < p + n - 1; i++) {
        long long tmp ;
        fscanf(rFile, "%lld", &tmp);
        t[i] = tmp;
    }

    //build
    for (int i = p - 2; i >= 0; i--) {
        t[i] = t[(i << 1) + 1] + t[(i << 1) + 2];
    }

    char word[3 + 1];
    while (fscanf(rFile, "%3s", word) != EOF) {
        if (word[1] == 'u') {
            int l, r;
            fscanf(rFile, "%d %d", &l, &r);
            long long ans = get(t, --l, --r, 0, 0, p - 1);
            fprintf(wFile, "%lld\n", ans);
        } else {
            int ind;
            long long data;
            fscanf(rFile, "%d %lld", &ind, &data);
            up(t, --ind, data, p);
        }
    }



    return 0;
}

long long get(const std::vector <long long> &t, int l, int r, int v, int tl, int tr) {
    if (tl >= l && r >= tr) {
        return t[v];
    }
    if (l > tr || r < tl) {
        return 0;
    }

    int mid = (tl + tr) / 2;
    return get(t, l, r, (v << 1) + 1, tl, mid) + get(t, l, r, (v << 1) + 2, mid + 1, tr);
}

void up(std::vector <long long> &t, int ind, long long data, int p) {
    int v = p - 1 + ind;
    t[v] = data;
    while (v != 0) {
        v = (v - 1) >> 1;
        t[v] = t[(v << 1) + 1] + t[(v << 1) + 2];
    }
}