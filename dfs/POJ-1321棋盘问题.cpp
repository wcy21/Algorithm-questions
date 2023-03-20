#include <iostream>

using namespace std;

int n, k, C = 0;
char m[10][10];
bool visRow[10];

void dfs(int x, int num) {
	if (num == k) {
		C += 1;
		return;
	}

	for (int i = x; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] == '#' && !visRow[j]) {
				visRow[j] = true;
				dfs(i + 1, num + 1);
				visRow[j] = false;
			}
		}
	}
}

int main() {
	while (cin >> n >> k) {
		if (n == -1 && k == -1)
			break;

		C = 0;
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
			visRow[i] = false;
		}
		dfs(0, 0);

		cout << C << endl;
	}

	return 0;
}
