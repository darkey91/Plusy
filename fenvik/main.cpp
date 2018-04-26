/*#include <vector>
#include <cstdio>

void build(std::vector<int> &f) {
    //идея: иду по массиву и  t[i] добавляю в ближайший нужный t[j]
    for (int i = 0; i < f.size(); i++) {
        int ind = i | (i + 1);
        if (ind < f.size()) {
            f[ind] += f[i];
        }
    }
}

void rebuild(std::vector<int> &f) {
    //идея : вот я на i и вычту все t[i] из эелементов, где они есть
    for (int i = 0; i < f.size(); i++) {
        for (int j = i | (i + 1); j < f.size(); j = j | (j + 1)) {
            f[j] -= f[i];
        }
    }

}

int main() {
    FILE *oFile, *wFile;
    oFile = fopen("sum.in", "r");
    wFile = fopen("sum.out", "w");

    std::vector<int> f;

    while (!feof(oFile)) {
         int d;
         fscanf(oFile, "%d", &d);

         f.push_back(d);
     }

    build(f);
    fprintf(wFile, "Build: ");
    for (int i = 0; i < f.size(); i++) {
        fprintf(wFile, "%d ", f[i]);
    }

    rebuild(f);
    fprintf(wFile, "\nRebuild: ");
    for (int i = 0; i < f.size(); i++) {
        fprintf(wFile, "%d ", f[i]);
    }

    return 0;
}
*/

#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

void up(std::vector<long long> &, int, long long);

long long sum(const std::vector<long long> &, int);

int F(int);

int main() {
    int n, k;
    FILE *pFile, *cFile;
    cFile = fopen("sum.out", "w");
    pFile = fopen("sum.in", "r");
    fscanf(pFile, "%d %d", &n, &k);
    //  std::ifstream in;
    // std::ofstream out;

    //in.open("sum.in");
    //out.open("sum.out");

    std::vector<long long> t(n + 1, 0);

    char sym;
    for (int i = 0; i < k; i++) {
        fscanf(pFile, "%s", &sym);
        if (sym == 'A') {
            int ind, x;
            fscanf(pFile, "%d %d", &ind, &x);
            up(t, --ind, x);
        } else {
            int l, r;
            fscanf(pFile, "%d %d", &l, &r);
            long long ans = sum(t, --r) - sum(t, --l - 1);
            if (ans == 0)
                ans = t[r];
            fprintf(cFile, "%lld\n", ans);
        }
    }


    return 0;
}

long long sum(const std::vector<long long> &t, int i) {
    long long res = 0;
    while (i >= 0) {
        res += t[i];
        i = F(i) - 1;
    }
    return res;
}

void up(std::vector<long long> &t, int ind, long long data) {
    long long diff =  data - t[ind];

    while (ind < t.size()) {
        t[ind] += data;
        ind = ind | (ind + 1);
    }
}

int F(int i) {
    int y = i & (i + 1);
    return y;
}
