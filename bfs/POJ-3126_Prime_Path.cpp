#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node {
    int x;
    int step;

    node(int _x, int _step): 
        x(_x), step(_step) {
    }
};

int cnt = 0, a[2007];
bool vis[10007];

int start, target;
int ret;

int cntP = 0, primes[2007];
bool visP[10007];

void Euler_prime(int n = 9999) {
    memset(visP, false, sizeof(visP));

    for (int i = 2; i <= n; ++i) {
        if (!visP[i]) {
            primes[cntP++] = i;
            if (i >= 1000)
                a[cnt++] = i;

            visP[i] = true;
        }
        for (int j = 0; j < cntP; ++j) {
            if (i * primes[j] > n)
                break;
            visP[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

bool valid(int dest, int src) {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        if (dest % 10 != src % 10)
            cnt += 1;
        dest /= 10, src /= 10;
    }
    return cnt == 1;
}

int bfs() {
    memset(vis, false, sizeof(vis));
    
    queue<node> q;
    vis[start] = true;
    q.push(node(start, 0));
    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (cur.x == target)
            return cur.step;

        for (int i = 0; i < cnt; ++i) {
            if (!vis[a[i]] && valid(a[i], cur.x)) {
                vis[a[i]] = true;
                q.push(node(a[i], cur.step + 1));
            }
        }
    }
    return -1;
}

int main() {
    Euler_prime();

    int n;
    cin >> n;
    while (n--) {
        cin >> start >> target;

        int ret = bfs();
        if(ret != -1)
            cout << ret << endl;
        else 
            cout << "Impossible" << endl;
    }

    return 0;
}
