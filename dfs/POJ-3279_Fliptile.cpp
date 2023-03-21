#include <iostream>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

int M, N;
int g[17][17], newg[17][17];
int temp[17][17], ans[17][17];
int minCnt = INF;

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

void dfs(int j, int cnt) {
    if (j > N) {
        memcpy(newg, g, sizeof(g));
        int tempCnt = 0;
        for (int x = 2; x <= M; ++x) {
            for (int y = 1; y <= N; ++y) {
                if (newg[x - 1][y] == 1) {
                    flip(newg, x, y);
                    temp[x][y] = 1;
                    tempCnt += 1;
                }
                else temp[x][y] = 0;
            }
        }

        if (valid() && cnt + tempCnt < minCnt) {
            memcpy(ans, temp, sizeof(temp));
            minCnt = cnt + tempCnt;
        }
        return;
    }

    temp[1][j] = 0;
    dfs(j + 1, cnt);

    flip(g, 1, j);
    temp[1][j] = 1;
    dfs(j + 1, cnt + 1);
    flip(g, 1, j);
}

int main() {
    cin >> M >> N;
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> g[i][j];

    dfs(1, 0);
    if (minCnt != INF) {
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j)
                cout << ans[i][j] << ' ';
            cout << endl;
        }
    }
    else 
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
