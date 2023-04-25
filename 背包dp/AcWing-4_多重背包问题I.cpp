#include <iostream>

using namespace std;

const int SIZE = 1007;

int n, W;
int w[SIZE], v[SIZE], c[SIZE];
int f[SIZE];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> v[i] >> c[i];

    for (int i = 0; i < n; ++i)
        for (int j = W; j >= w[i]; --j)
            for (int k = 0; k <= c[i]; ++k)
                if (j >= k * w[i])
                    f[j] = max(f[j], f[j - w[i] * k] + v[i] * k);

    cout << f[W] << endl;

    return 0;
}
