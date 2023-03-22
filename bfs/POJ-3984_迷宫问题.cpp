#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int x, y;
    string path;

    node(int _x, int _y, string _path) :
        x(_x), y(_y), path(_path) {
    }
};

int N = 5;
int g[7][7];
bool vis[7][7];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

string to_s(int i, int j) {
    return "\n(" + string(1, i + '0') + ", " + string(1, j + '0') + ")";
}

void bfs() {
    memset(vis, false, sizeof(vis));

    queue<node> q;
    q.push(node(0, 0, "(0, 0)"));
    vis[0][0] = true;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (cur.x == N - 1 && cur.y == N - 1) {
            cout << cur.path << endl;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int px = cur.x + dx[i];
            int py = cur.y + dy[i];
            if (px >= 0 && px < N && py >= 0 && py < N &&
                g[px][py] == 0 && !vis[px][py]) {
                q.push(node(px, py, cur.path + to_s(px, py)));
                vis[px][py] = true;
            }
        }
    }
}

int main() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> g[i][j];

    bfs();

    return 0;
}
