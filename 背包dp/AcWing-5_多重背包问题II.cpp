#include <iostream>

using namespace std;

const int SIZE = 30007;

int n, W, idx = 0;
int w[SIZE], v[SIZE];
int f[SIZE];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) {
        int k = 1, ci, wi, vi;
        cin >> wi >> vi >> ci;
        while (k < ci) {
            w[idx] = k * wi;
            v[idx++] = k * vi;
            ci -= k;
            k *= 2;
        }
        w[idx] = ci * wi;
        v[idx++] = ci * vi;
    }

    for (int i = 0; i < idx; ++i)
        for (int j = W; j >= w[i]; --j) 
            f[j] = max(f[j], f[j - w[i]] + v[i]);

    cout << f[W] << endl;

    return 0;
}
