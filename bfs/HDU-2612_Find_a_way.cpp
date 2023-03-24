#include <iostream>
#include <cstring>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

struct node {
    int x, y;
    int step;

    node(int _x, int _y, int _step) :
        x(_x), y(_y), step(_step) {
    }
};

int n, m;
char g[207][207];
bool vis[207][207][2];
int dis[207][207][2];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

inline void PUSH(queue<node>& q, node t, int k) {
    if (t.x >= 0 && t.x < n && t.y >= 0 && t.y < m 
        && g[t.x][t.y] != '#' && !vis[t.x][t.y][k]) {
        vis[t.x][t.y][k] = true;
        q.push(t);
    }
}

void bfs(int x, int y, int k) {
    queue<node> q;
    PUSH(q, node(x, y, 0), k);
    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (g[cur.x][cur.y] == '@')
            if (cur.step < dis[cur.x][cur.y][k])
                dis[cur.x][cur.y][k] = cur.step;

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                PUSH(q, node(cur.x + dx[i], cur.y + dy[i], cur.step + 1), k);
    }
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dis[i][j][0] = dis[i][j][1] = INF;

        for (int i = 0; i < n; ++i)
            cin >> g[i];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'Y') {
                    memset(vis, false, sizeof(vis));
                    bfs(i, j, 0);
                }
                if (g[i][j] == 'M') {
                    memset(vis, false, sizeof(vis));
                    bfs(i, j, 1);
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (g[i][j] == '@')
                    ans = min(ans, (dis[i][j][0] + dis[i][j][1]) * 11);

        cout << ans << endl;
    }

    return 0;
}
