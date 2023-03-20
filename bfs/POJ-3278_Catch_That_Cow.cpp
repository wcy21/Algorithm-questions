#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, K;
int a[100007];
bool vis[100007];

struct node {
	int x;
	int step;

    node(int _x, int _step):
        x(_x),  step(_step){
    }
};

void bfs() {
	queue<node> q;
    vis[N] = true;
	q.push(node(N, 0));
	while (!q.empty()) {
		node cur = q.front();
        q.pop();
		if (cur.x == K) {
            cout << cur.step << endl;
			return;
		}

        node temp(cur.x + 1, cur.step + 1);
        if (!vis[temp.x] && temp.x >= 0 && temp.x <= 100007) {
            vis[temp.x] = true;
            q.push(temp);
        }

        temp = node(cur.x - 1, cur.step + 1);
        if (!vis[temp.x] && temp.x >= 0 && temp.x <= 100007) {
            vis[temp.x] = true;
            q.push(temp);
        }

        temp = node(cur.x * 2, cur.step + 1);
        if (!vis[temp.x] && temp.x >= 0 && temp.x <= 100007) {
            vis[temp.x] = true;
            q.push(temp);
        }
	}
}

int main() {
    memset(vis, false, sizeof(vis));

    cin >> N >> K;
    bfs();

	return 0;
}
