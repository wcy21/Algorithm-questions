#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll cnt = 0, a[20007];
ll l, r, L, R, ans = 0;

void dfs(long long i) {
    if (i > 1000000000)
        return;
    a[cnt++] = i;
    dfs(i * 10 + 4);
    dfs(i * 10 + 7);
}

int main() {
    dfs(4);
    dfs(7);
    a[cnt++] = 4444444444;
    sort(a, a + cnt);

    cin >> l >> r;
    L = lower_bound(a, a + cnt, l) - a;
    R = lower_bound(a, a + cnt, r) - a;

    for (int i = L; i <= R; ++i) {
        ans += (min(a[i], r) - l + 1) * a[i];
        l = a[i] + 1;
    }
    cout << ans << endl;

    return 0;
}
