#include <iostream>
#include <algorithm>
#include <queue>

#define MAXN 362887

using namespace std;

struct node {
    int hashs;
    int pos;
    int puz[10];

    node(int _hashs, int _pos, int _puz[10]) :
        hashs(_hashs), pos(_pos) {
        for (int i = 0; i < 10; ++i)
            this->puz[i] = _puz[i];
    }
};

struct step {
    char dire;
    int pre;
}steps[MAXN];

int fact[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int puzzle[10];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char op[4] = { 'l', 'u', 'r', 'd' };

int cantor(int* a) {
    int ret = 1;
    for (int i = 0; i < 9; ++i) {
        int cnt = 0;
        for (int j = i + 1; j < 9; ++j)
            if (a[i] > a[j])
                cnt += 1;

        ret += cnt * fact[8 - i];
    }
    return ret;
}

void decantor(int* a, int n) {
    vector<int> v;
    for (int i = 0; i < 9; ++i)
        v.push_back(i);

    for (int i = 0; i < 9; ++i) {
        sort(v.begin(), v.end());
        int x = n / fact[8 - i];
        n -= x * fact[8 - i];
        a[i] = v[x];
        v.erase(v.begin() + x);
    }
}

void bfs() {
    for (int i = 0; i < 8; ++i)
        puzzle[i] = i + 1;
    puzzle[8] = 0;

    queue<node> q;
    steps[cantor(puzzle)].pre = 0;
    q.push(node(cantor(puzzle), 8, puzzle));
    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int x = cur.pos / 3 + dx[i];
            int y = cur.pos % 3 + dy[i];

            if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
                node temp(-1, 3 * x + y, cur.puz);
                swap(temp.puz[temp.pos], temp.puz[cur.pos]);
                temp.hashs = cantor(temp.puz);
                if (steps[temp.hashs].pre == -1) {
                    steps[temp.hashs].dire = op[i];
                    steps[temp.hashs].pre = cur.hashs;
                    q.push(temp);
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < MAXN; ++i)
        steps[i].pre = -1;

    bfs();

    char c;
    int hashs;
    while (cin >> c) {
        if (c == 'x')
            puzzle[0] = 0;
        else
            puzzle[0] = c - '0';

        for (int i = 1; i < 9; ++i) {
            cin >> c;
            if (c == 'x')
                puzzle[i] = 0;
            else
                puzzle[i] = c - '0';
        }
        hashs = cantor(puzzle);
        if (steps[hashs].pre == -1)
            cout << "unsolvable" << endl;
        else {
            while (hashs != 0) {
                cout << steps[hashs].dire;
                hashs = steps[hashs].pre;
            }
            cout << endl;
        }
    }

    return 0;
}
