#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int s, n, m;
    int step;

    node(int _s, int _n, int _m, int _step) :
        s(_s), n(_n), m(_m), step(_step) {
    }
};

int S, N, M, avg;
bool vis[107][107];

inline void PUSH(queue<node>& q, node x) {
    if (!vis[x.n][x.m]) {
        q.push(x);
        vis[x.n][x.m] = true;
    }
}

void bfs() {
    if (S % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    avg = (N + M) / 2;
    memset(vis, 0, sizeof(vis));

    queue<node> q;
    PUSH(q, node(S, 0, 0, 0));
    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if ((cur.n == avg && cur.m == avg) || (cur.m == avg && cur.s == avg)
            || (cur.n == avg && cur.s == avg)) {
            cout << cur.step << endl;
            return;
        }

        int sn = min(cur.s, N - cur.n);
        PUSH(q, node(cur.s - sn, cur.n + sn, cur.m, cur.step + 1));
        PUSH(q, node(cur.s + cur.n, 0, cur.m, cur.step + 1));

        int sm = min(cur.s, M - cur.m);
        PUSH(q, node(cur.s - sm, cur.n, cur.m + sm, cur.step + 1));
        PUSH(q, node(cur.s + cur.m, cur.n, 0, cur.step + 1));

        int nm = min(cur.n, M - cur.m);
        PUSH(q, node(cur.s, cur.n - nm, cur.m + nm, cur.step + 1));
        int mn = min(N - cur.n, cur.m);
        PUSH(q, node(cur.s, cur.n + mn, cur.m - mn, cur.step + 1));
    }
    cout << "NO" << endl;
    return;
}

int main() {
    while (cin >> S >> N >> M) {
        if (S == 0 && N == 0 && M == 0)
            break;

        bfs();
    }

    return 0;
}
