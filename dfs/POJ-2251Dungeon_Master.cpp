#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int L, R, C;
int sx, sy, sz;
char m[33][33][33];
bool vis[33][33][33];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 0, 0, 1, -1 };
int dz[6] = { 0, 0, -1, 1, 0, 0 };

struct node {
	int x;
	int y;
	int z;
	int step;

    node(int _x, int _y, int _z, int _step):
        x(_x), y(_y), z(_z), step(_step){
    }

	bool operator<(const node& n) const {
		return this->step > n.step;
	}
};

void bfs() {
	priority_queue<node> q;
    vis[sx][sy][sz] = true;
	q.push(node(sx, sy, sz, 0));
	while (!q.empty()) {
		node cur = q.top();
        q.pop();
		if (m[cur.x][cur.y][cur.z] == 'E') {
            cout << "Escaped in " << cur.step << " minute(s)." << endl;
			return;
		}
		for (int i = 0; i < 6; ++i) {
			node temp(cur.x + dx[i], cur.y + dy[i], cur.z + dz[i], cur.step + 1);
			if (temp.x >= 0 && temp.x < L && temp.y >= 0 && temp.y < R
				&& temp.z >= 0 && temp.z < C && m[temp.x][temp.y][temp.z] != '#') {
				if (!vis[temp.x][temp.y][temp.z]) {
					vis[temp.x][temp.y][temp.z] = true;
					q.push(temp);
				}
			}
		}
	}
    cout << "Trapped!" << endl;
}

int main() {
	while (cin >> L >> R >> C) {
		if (L == 0 && R == 0 && C == 0)
			break;
		
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < R; ++j)
				cin >> m[i][j];

		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					if (m[i][j][k] == 'S') {
						sx = i;
						sy = j;
						sz = k;
					}
				}
			}
		}

		bfs();
	}

	return 0;
}
