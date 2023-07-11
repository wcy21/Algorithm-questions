#include <iostream>

using namespace std;

typedef pair<int, int> PII;

int g[10][10], cnt = 0;
PII blank[82];
bool r[10][10], v[10][10], s[10][10];

void dfs(int i) {
    if (i == cnt) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                cout << g[i][j] << (j == 8 ? '\n' : ' ');
        return;
    }

    int x = blank[i].first, y = blank[i].second;
    for (int j = 1; j <= 9; ++j) {
        if (!r[x][j] && !v[y][j] && !s[x / 3 + y / 3 * 3][j]) {
            r[x][j] = v[y][j] = s[x / 3 + y / 3 * 3][j] = true;
            g[x][y] = j;
            dfs(i + 1);
            r[x][j] = v[y][j] = s[x / 3 + y / 3 * 3][j] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int num;
            cin >> num;
            g[i][j] = num;

            if (!num)
                blank[cnt++] = {i, j};
            else
                r[i][num] = v[j][num] = s[i / 3 + j / 3 * 3][num] = true;
        }
    }

    dfs(0);

    return 0;
}
