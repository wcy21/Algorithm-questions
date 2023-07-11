#include <iostream>

using namespace std;

char g[507][507];
bool flag;
int n, m, sx, sy;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    if (g[x][y] == 't') {
        flag = true;
        return;
    }

    g[x][y] = 'x';
    for (int i = 0; i < 4; ++i) {
        if (flag == true)
            return;

        int px = x + dx[i];
        int py = y + dy[i];
        if (g[px][py] != 'x' && px >= 1 && px <= n && py >= 1 && py <= m)
            dfs(px, py);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        flag = 0;
        for (int i = 1; i <= n; ++i) {
            cin.get();
            for (int j = 1; j <= m; ++j) {
                g[i][j] = cin.get();
                if (g[i][j] == 's')
                    sx = i, sy = j;
            }
        }
        dfs(sx, sy);

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
