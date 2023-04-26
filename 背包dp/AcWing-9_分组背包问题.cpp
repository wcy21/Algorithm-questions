#include <iostream>

using namespace std;

const int N = 107;

int n, W;
int s[N], w[N][N], v[N][N];
int f[N];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i]; ++j)
            cin >> w[i][j] >> v[i][j];
    }

    for (int i = 0; i < n; ++i)
        for (int j = W; j >= 0; --j)
            for (int k = 0; k < s[i]; ++k)
                if (j >= w[i][k])
                    f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);

    cout << f[W] << endl;

    return 0;
}
