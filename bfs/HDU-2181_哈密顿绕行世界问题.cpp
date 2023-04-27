#include <iostream>
#include <vector>

using namespace std;

const int N = 20;

int g[N + 1][N + 1];
bool vis[N + 1];
int st, cnt = 0;
vector<int> path;

void bfs(int e) {
    if (e == st && !path.empty() && path.size() != N)   
        return;

    if (path.size() == N) {
        cout << ++cnt << ":  " << st;
        for (int i = 0; i < path.size(); ++i)
            cout << ' ' << path[i];
        cout << endl;
        return;
    }

    for (int i = 1; i <= 20; ++i) {
        if (!vis[i] && g[e][i]) {
            vis[i] = true;
            path.push_back(i);
            bfs(i);
            path.pop_back();
            vis[i] = false;
        }
    }
}

int main() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            int e;
            cin >> e;
            g[i][e] = g[e][i] = 1;
        }
    }
    while (cin >> st) {
        if (st == 0)   
            break;
        path.clear();
        cnt = 0;
        bfs(st);
    }
    
    return 0;
}
