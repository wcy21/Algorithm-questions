#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define MAXN 362887

using namespace std;

struct node {
    int hashs;
    int pos;
    char puz[10];

    node(int _hashs, int _pos, char _puz[10]) :
        hashs(_hashs), pos(_pos){
        memcpy(this->puz, _puz, 10);
    }
};

struct step {
    char dire;
    int pre;
} steps[MAXN];

int fact[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

char puzzle[10];
char state[10] = "123456780";

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char op[4] = { 'l', 'u', 'r', 'd' };

int cantor(char* a) {
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

void bfs() {
    for (int i = 0; i < MAXN; ++i)
        steps[i].pre = -1;
    memcpy(puzzle, state, 10);

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
    bfs();
    
    int hashs;
    while (cin >> puzzle[0]) {
        if (puzzle[0] == 'x')
            puzzle[0] = '0';
        for (int i = 1; i < 9; ++i) {
            cin >> puzzle[i];
            if (puzzle[i] == 'x')
                puzzle[i] = '0';
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
