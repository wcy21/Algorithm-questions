#include <iostream>

using namespace std;

char g[107][107];
int N, M, ans = 0;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int x, int y) {
    g[x][y] = '.';

    for (int i = 0; i < 8; ++i) {
        int px = x + dx[i];
        int py = y + dy[i];
        if (px >= 1 && px <= N && py >= 1 && py <= M && g[px][py] == 'W')
            dfs(px, py);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> g[i] + 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (g[i][j] == 'W') {
                ans += 1;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
