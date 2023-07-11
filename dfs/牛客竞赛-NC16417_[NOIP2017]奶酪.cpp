#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

struct sph {
    long long x, y, z;
    bool operator<(const sph &n) const { return z < n.z; }
} p[1007];
bool flag, vis[1007];

int n, h, r;

double dis(sph &a, sph &b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) +
                (b.z - a.z) * (b.z - a.z));
}

void dfs(sph cur, int no) {
    if (cur.z + r >= h) {
        flag = true;
        return;
    }

    vis[no] = true;

    for (int i = 0; i < n; ++i) {
        if (flag == true)
            return;
        if (!vis[i] && dis(cur, p[i]) <= r * 2)
            dfs(p[i], i);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(vis, false, sizeof(vis));
        memset(p, 0, sizeof(p));
        flag = false;

        cin >> n >> h >> r;
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y >> p[i].z;
        sort(p, p + n);
        for (int i = 0; i < n; ++i)
            if (p[i].z <= r)
                dfs(p[i], i);

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
