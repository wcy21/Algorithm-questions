#include <iostream>
#include <queue>

using namespace std;

int M, N, L, T;
int g[67][1307][137];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct node {
	int z, x, y;

	node(int _z, int _x, int _y) :
		z(_z), x(_x), y(_y) {
	}
};

int bfs(int z, int x, int y) {
	int cnt = 0;
	queue<node> q;
	q.push(node(z, x, y));
	g[z][x][y] = 0;
	cnt += 1;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();

 		for (int i = 0; i < 6; ++i) {
			node temp(cur.z + dz[i], cur.x + dx[i], cur.y + dy[i]);
			if (temp.z >= 1 && temp.z <= L && temp.x >= 1 && temp.x <= M
				&& temp.y >= 1 && temp.y <= N && g[temp.z][temp.x][temp.y] == 1) {
				q.push(temp);
				g[temp.z][temp.x][temp.y] = 0;
				cnt += 1;
			}
		}
	}
	if (cnt >= T)
		return cnt;
	return 0;
}

int main() {
	cin >> M >> N >> L >> T;
	for (int z = 1; z <= L; ++z)
		for (int x = 1; x <= M; ++x)
			for (int y = 1; y <= N; ++y)
				cin >> g[z][x][y];

	int totalVolumn = 0;
	for (int z = 1; z <= L; ++z)
		for (int x = 1; x <= M; ++x)
			for (int y = 1; y <= N; ++y)
				if (g[z][x][y] == 1)
					totalVolumn += bfs(z, x, y);

	cout << totalVolumn << endl;

	return 0;
}
