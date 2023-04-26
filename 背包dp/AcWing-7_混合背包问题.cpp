#include <iostream>

using namespace std;

const int N = 20007;

int n, W, cnt = 0;
int w[N], v[N];
int f[N];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) {
        int k = 1, wi, vi, ci;
        cin >> wi >> vi >> ci;
        if (ci == -1) ci = 1; 
        if (ci == 0) ci = W / wi;
        while (k < ci) {
            w[cnt] = k * wi;
            v[cnt++] = k * vi;
            ci -= k;
            k *= 2;
        }
        w[cnt] = ci * wi;
        v[cnt++] = ci * vi;
    }

    n = cnt;
    for (int i = 0; i < n; ++i)
        for (int j = W; j >= w[i]; --j) 
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    
    cout << f[W] << endl;

    return 0;
}
