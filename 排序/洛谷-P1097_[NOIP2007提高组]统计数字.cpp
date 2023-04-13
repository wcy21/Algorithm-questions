#include <iostream>

using namespace std;

void quick_sort(int q[], int l, int r) {
	if (l >= r) return;

	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while (i < j) {
		do ++i; while (q[i] < x);
		do --j; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}

	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}

int n, a[200007];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	quick_sort(a, 0, n - 1);

	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		if (i == n || a[i] != a[i - 1]) {
			cout << a[i - 1] << ' ' << cnt << endl;
			cnt = 1;
		}
		else
			cnt += 1;
	}

	return 0;
}
