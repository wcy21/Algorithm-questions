#include <iostream>

#define MAXN 100007

using namespace std;

struct node {
    int w;
    int v;
} l[MAXN];
int n, W, idx = 0;
int f[MAXN];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) {
        int c = 1, vi, wi, mi;
        cin >> vi >> wi >> mi;
        while (mi > c) {
            mi -= c;
            l[idx].v += c * vi;
            l[idx++].w += c * wi;
            c <<= 1;
        }
        l[idx].v += mi * vi;
        l[idx++].w += mi * wi;
    }

    for (int i = 0; i < idx; ++i)
        for (int j = W; j >= l[i].w; --j)
            f[j] = max(f[j], f[j - l[i].w] + l[i].v);

    cout << f[W] << endl;

    return 0;
}
