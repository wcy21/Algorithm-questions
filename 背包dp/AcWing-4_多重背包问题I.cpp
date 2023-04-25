#include <iostream>

using namespace std;

const int SIZE = 1007;

struct node {
    int w, v;
} l[SIZE];
int n, W, idx = 0;
int f[SIZE];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) {
        int k = 1, ci, wi, vi;
        cin >> wi >> vi >> ci;
        while (k < ci) {
            l[idx].w = k * wi;
            l[idx++].v = k * vi;
            ci -= k;
            k <<= 1;
        }
        l[idx].w = ci * wi;
        l[idx++].v = ci * vi;
    }

    for (int i = 0; i < idx; ++i)
        for (int j = W; j >= l[i].w; --j) 
            f[j] = max(f[j], f[j - l[i].w] + l[i].v);

    cout << f[W] << endl;

    return 0;
}
