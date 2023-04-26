#include <iostream>
#include <cstring>

using namespace std;

const int N = 20007;

int f[N], g[N], q[N];
int n, W;

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; ++i) {
        memcpy(g, f, sizeof(f));
        int w, v, c;
        cin >> w >> v >> c;
        for (int j = 0; j < w; ++j) {
            int head = 0, tail = -1;
            for (int k = j; k <= W; k += w) {
                if (head <= tail && k - c * w > q[head])
                    ++head;
                while (head <= tail && g[q[tail]] - (q[tail] - j) / w * v <= g[k] - (k - j) / w * v)
                    --tail; 
                if (head <= tail)
                    f[k] = max(f[k], g[q[head]] + (k - q[head]) / w * v);
                q[++tail] = k;
            }
        }
    }
    cout << f[W] << endl;

    return 0;
}
