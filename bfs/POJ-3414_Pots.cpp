#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct node{
    int a, b;
    int step;
    string path;

    node(int _a, int _b, int _step, string _path) :
        a(_a), b(_b), step(_step), path(_path) {
    }
};

char s_op[7][17] = {
    "\nFILL(1)",
    "\nFILL(2)",
    "\nDROP(1)",
    "\nDROP(2)",
    "\nPOUR(1,2)",
    "\nPOUR(2,1)"
};

int A, B, C;
bool vis[107][107];

inline void PUSH(queue<node>& q, node n) {
    if (!vis[n.a][n.b]) {
        q.push(n);
        vis[n.a][n.b] = true;
    }
}

void FILL(queue<node>& q, node n, int i) {
    if (i == 1)
        n.a = A;
    else
        n.b = B;

    PUSH(q, node(n.a, n.b, n.step + 1, n.path + s_op[i - 1]));
}

void DROP(queue<node>& q, node n, int i) {
    if (i == 1)
        n.a = 0;
    else
        n.b = 0;

    PUSH(q, node(n.a, n.b, n.step + 1, n.path + s_op[i + 1]));
}

void POUR(queue<node>& q, node n, int i, int j) {
    int pour = 0;
    if (i == 1)
        pour = min(n.a, B - n.b);
    else
        pour = -min(n.b, A - n.a);
    n.a -= pour;
    n.b += pour;

    PUSH(q, node(n.a, n.b, n.step + 1, n.path + s_op[i + 3]));
}

void bfs() {
    memset(vis, 0, sizeof(vis));

    queue<node> q;
    PUSH(q, node(0, 0, 0, ""));
    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (cur.a == C || cur.b == C) {
            cout << cur.step << cur.path << endl;
            return;
        }

        for (int i = 1; i <= 2; ++i) {
            FILL(q, cur, i);
            DROP(q, cur, i);
            POUR(q, cur, i, 3 - i);
        }
    }
    cout << "impossible" << endl;
    return;
}

int main() {
    cin >> A >> B >> C;
    bfs();

    return 0;
}
