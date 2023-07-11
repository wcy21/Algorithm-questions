#include <iostream>

using namespace std;

int n, m, ans = 0;
int dx[4] = {1, 1, 2, 2};
int dy[4] = {2, -2, 1, -1};

void dfs(int x, int y) {
    if (x == n && y == m) {
        ans += 1;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int px = x + dx[i], py = y + dy[i];
        if (px >= 1 && px <= n && py >= 1 && py <= m)
            dfs(px, py);
    }
}

int main() {
    cin >> m >> n;
    dfs(1, 1);
    cout << ans << endl;

    return 0;
}
