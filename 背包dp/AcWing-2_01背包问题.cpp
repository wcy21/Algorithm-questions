#include <iostream>

using namespace std;

const int SIZE = 1007;

int n, W;
int v[SIZE], w[SIZE];
int f[SIZE];

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> v[i];
    
    for (int i = 0; i < n; ++i)
        for (int j = W; j >= w[i]; --j)
            f[j] = max(f[j], f[j - w[i]] + v[i]);

    cout << f[W] << endl;

    return 0;
}
