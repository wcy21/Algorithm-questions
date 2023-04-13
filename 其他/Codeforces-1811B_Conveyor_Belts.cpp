#include <iostream>
#include <algorithm>

using namespace std;

int level(int n, int x, int y) {
	return min({ x, n + 1 - x, y ,n + 1 - y });
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, x1, y1, x2, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;

		int ans = abs(level(n, x1, y1) - level(n, x2, y2));
		cout << ans << endl;
	}

	return 0;
}
