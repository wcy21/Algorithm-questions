#include <iostream>
#include <cstring>

using namespace std;

const int N = 107;

int n, W;
int h[N], e[N], ne[N], idx;
int w[N], v[N];
int f[N][N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        dfs(son);
        for (int j = W - w[u]; j >= 0; --j)
            for (int k = 0; k <= j; ++k)
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
    }
    for (int i = W; i >= w[u]; --i)
        f[u][i] = f[u][i - w[u]] + v[u];
    for (int i = 0; i < w[u]; ++i)
        f[u][i] = 0;
}

int main() {
    memset(h, -1, sizeof(h));

    cin >> n >> W;
    int root, p;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i] >> p;
        if (p == -1)
            root = i;
        else
            add(p, i);
    }
    dfs(root);
    cout << f[root][W] << endl;

    return 0;
}
