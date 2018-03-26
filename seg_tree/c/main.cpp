#include <climits>
#include <cstdio>
#include <vector>
#include <fstream>
#include <string>

int n, p;
long long neutralElem = LLONG_MAX;

struct ver {
    long long data = neutralElem;
    bool update = false;
    long long new_data = 0;
    long long add = 0;
};

void build(std::vector<ver> &t, int v, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(t, (v << 1) + 1, l, mid);
    build(t, (v << 1) + 2, mid + 1, r);
    t[v].data = std::min(t[(v << 1) + 1].data, t[(v << 1) + 2].data);
}

void  change(std::vector<ver> &t, int v) {
    t[v].data += t[v].add;
    t[v].add = 0;
    if (t[v].update) {
        t[v].data = t[v].new_data;
    }

    t[v].update = false;
}

void push(std::vector<ver> &t, int v) {
    if ((v << 1) + 1 < p - 1 + n) {
        t[(v << 1) + 1].update = t[v].update;
        t[(v << 1) + 1].add = t[v].add;
        t[(v << 1) + 1].new_data = t[v].new_data;

    }
    if ((v << 1) + 2 < p - 1 + n) {
        t[(v << 1) + 2].update = t[v].update;
        t[(v << 1) + 2].add = t[v].add;
        t[(v << 1) + 2].new_data = t[v].new_data;
    }
    change(t, v);
}

void update(std::vector<ver> &t, int v, int l, int r, int tl, int tr, int data, bool up) {
    if (l > tr || r < tl)
        return;

    if (l <= tl && tr <= r) {
        if (up) {
            t[v].add = 0;
            t[v].update = true;
            t[v].new_data = data;
        } else {
            if (t[v].update) {
                t[v].new_data += data;
            } else {
                t[v].add += data;
            }
        }
        return;
    }


    int mid = (tl + tr) >> 1;
    update(t, (v << 1) + 1, l, r, tl, mid, data, up);
    update(t, (v << 1) + 2, l, r, mid + 1, tr, data, up);

    t[v].data = std::min((t[(v << 1) + 1].update)?t[(v << 1) + 1].new_data : t[(v << 1) + 1].data += t[(v << 1) + 1].add,
                         (t[(v << 1) + 2].update)?t[(v << 1) + 2].new_data : t[(v << 1) + 2].data += t[(v << 1) + 2].add);
}

long long get_min(std::vector<ver> &t, int l, int r, int v, int tl, int tr) {
    if (l > tr || tl > r) {
        return LLONG_MAX;
    }

    if (tl >= l && tr <= r) {
        return (t[v].update)?t[v].new_data : t[v].data += t[v].add;
    }

    int mid = (tl + tr) >> 1;
    push(t, v);
    return std::min(
            get_min(t, l, r, (v << 1) + 1, tl, mid),
            get_min(t, l, r, (v << 1) + 2, mid + 1, tr)
    );
}

int main() {
    /* FILE *in, *out;
     in = fopen("rmq2.in", "r");
     out = fopen("rmq2.out", "w");

     fscanf(in, "%d", &n);*/
    std::ifstream in;
    std::ofstream out;
    in.open("rmq2.in");
    out.open("rmq2.out");
    in >> n;

    p = 1;
    while (p < n) {
        p <<= 1;
    }
    std::vector<ver> t((p << 1) - 1);

    for (int i = p - 1; i < n + p - 1; ++i) {
        //fscanf(in, "%lld", &t[i].data);
        in >> t[i].data;
    }

    build(t, 0, 0, p - 1);

    //char word[3 + 1];
    std::string word;

    while (in >> word) {
        switch (word[0]) {
            case 's': {
                int l, r;
                long long data;
                //fscanf(in, "%d%d%lld", &l, &r, &data);
                in >> l >> r >> data;
                update(t, 0, --l, --r, 0, p - 1, data, true);
                break;
            }
            case 'a': {
                int l, r;
                long long data;
                // fscanf(in, "%d%d%lld", &l, &r, &data);
                in >> l >> r >> data;
                update(t, 0, --l, --r, 0, p - 1, data, false);

                break;
            }
            case 'm': {
                int l, r;
                //fscanf(in, "%d%d", &l, &r);
                in >> l >> r;
                long long ans = get_min(t, --l, --r, 0, 0, p - 1);
                out << ans << std::endl;
                //fprintf(out, "%lld\n", ans);
            }
        }
    }

    return 0;
}

