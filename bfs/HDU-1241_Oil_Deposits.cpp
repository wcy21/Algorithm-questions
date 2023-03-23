#include <iostream>
#include <queue>

using namespace std;

int m, n;
char g[107][107];

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

struct node {
	int x, y;

	node(int _x, int _y) :
		x(_x), y(_y) {
	}
};

void bfs(int x, int y) {
	queue<node> q;
	q.push(node(x, y));
	g[x][y] = 0;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();

 		for (int i = 0; i < 8; ++i) {
			node temp(cur.x + dx[i], cur.y + dy[i]);
			if (temp.x >= 0 && temp.x < m && temp.y >= 0 && temp.y < n
				&& g[temp.x][temp.y] == '@') {
				q.push(temp);
				g[temp.x][temp.y] = '*';
			}
		}
	}
}

int main() {
	while (cin >> m >> n) {
		if (m == 0)
			break;

		for (int x = 0; x < m; ++x)
			cin >> g[x];

		int count = 0;
		for (int x = 0; x < m; ++x) {
			for (int y = 0; y < n; ++y) {
				if (g[x][y] == '@') {
					bfs(x, y);
					count += 1;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
