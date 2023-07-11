#include <iostream>

using namespace std;

int a[9];
bool vis[9];

void dfs(int i) {
    if (i == 8) {
        for (int i = 1; i < 8; ++i)
            cout << a[i] << ' ';
        cout << a[8] << endl;
        return;
    }
    for (int j = 1; j <= 8; ++j) {
        if (!vis[j]) {
            a[i + 1] = j;
            vis[j] = true;
            dfs(i + 1);
            vis[j] = false;
        }
    }
}

int main() {
    dfs(0);

    return 0;
}
