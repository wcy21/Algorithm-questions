#include <iostream>

using namespace std;

const int N = 1007;

int n, W;
int s[N], w[N][N], v[N][N];
int f[N];

int main() {
    cin >> W >> n;
    for (int i = 0; i < n; ++i) {
        int wi, vi, si;
        cin >> wi >> vi >> si;
        w[si][s[si]] = wi;
        v[si][s[si]] = vi;
        s[si]++;
    }

    for (int i = 0; i < N; ++i)
        for (int j = W; j >= 0; --j)
            for (int k = 0; k < s[i]; ++k)
                if (j >= w[i][k])
                    f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);

    cout << f[W] << endl;

    return 0;
}
