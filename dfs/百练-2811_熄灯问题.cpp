#include <iostream>
#include <cstring>

using namespace std;

int M = 5, N = 6;
int g[17][17], newg[17][17];
int temp[17][17], ans[17][17];
bool flag = false;

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };

void flip(int a[17][17], int x, int y) {
    for (int i = 0; i < 5; ++i)
        a[x + dx[i]][y + dy[i]] ^= 1;
}

bool valid() {
    for (int y = 1; y <= N; ++y)
        if (newg[M][y] == 1)
            return false;

    return true;
}

void dfs(int j) {
    if (flag)
        return;
    if (j > N) {
        memcpy(newg, g, sizeof(g));
        for (int x = 2; x <= M; ++x) {
            for (int y = 1; y <= N; ++y) {
                if (newg[x - 1][y] == 1) {
                    flip(newg, x, y);
                    temp[x][y] = 1;
                }
                else temp[x][y] = 0;
            }
        }

        if (valid()) {
            memcpy(ans, temp, sizeof(temp));
        }
        return;
    }

    temp[1][j] = 0;
    dfs(j + 1);

    flip(g, 1, j);
    temp[1][j] = 1;
    dfs(j + 1);
    flip(g, 1, j);
}

int main() {
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> g[i][j];

    dfs(1);
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
