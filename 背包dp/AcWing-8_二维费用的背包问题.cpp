#include <iostream>

using namespace std;

const int N = 1007;

int n, W, T;
int w[N], t[N], v[N];
int f[N][N];

int main() {
    cin >> n >> W >> T;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> t[i] >> v[i];

    for (int k = 0; k < n; ++k)
        for (int i = W; i >= w[k]; --i)
            for (int j = T; j >= t[k]; --j)
                f[i][j] = max(f[i][j], f[i - w[k]][j - t[k]] + v[k]);
                
    cout << f[W][T] << endl;

    return 0;
}
