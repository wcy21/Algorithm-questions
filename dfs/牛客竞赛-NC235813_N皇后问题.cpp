#include <iostream>

using namespace std;

int n, ans = 0;
bool g[13][13];
bool r[13], od[26], bd[26];

void dfs(int i) {
    if (i == n) {
        ans += 1;
        return;
    }

    for (int j = 0; j < n; ++j) {
        if (!r[j] && !od[n + i - j] && !bd[i + j]) {
            g[i][j] = true;
            r[j] = od[n + i - j] = bd[i + j] = true;
            dfs(i + 1);
            g[i][j] = false;
            r[j] = od[n + i - j] = bd[i + j] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans << endl;

    return 0;
}
