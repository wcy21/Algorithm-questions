#include <iostream>
#include <cstring>

using namespace std;

const int N = 1007;
const int M = 3207;

int n, W;
int h[N], e[N], ne[N], idx;
int w[M], v[M];
int f[N][M];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        dfs(son);
        for (int j = W; j >= w[son]; --j)
            for (int k = j; k >= w[son]; --k)
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
    }
    if (u != 0)
        for (int i = W; i >= w[u]; --i)
            f[u][i] = f[u][i - w[u]] + v[u];
    for (int i = 0; i < w[u]; ++i)
        f[u][i] = 0;
}

int main() {
    memset(h, -1, sizeof(h));

    cin >> W >> n;
    W /= 10;
    int p;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i] >> p;
        w[i] /= 10;
        v[i] *= w[i];
        add(p, i);
    }
    dfs(0);
    cout << f[0][W] * 10 << endl;

    return 0;
}
