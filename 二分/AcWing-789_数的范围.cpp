#include <iostream>

using namespace std;

int n, q, k, a[100007];

int b_search1(int l, int r) {
	while (l < r) {
		int mid = l + r >> 1;
		if (a[mid] >= k) r = mid;
		else l = mid + 1;
	}
	return a[l] == k ? l : -1;
}

int b_search2(int l, int r) {
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (a[mid] <= k) l = mid;
		else r = mid - 1;
	}
	return a[l] == k ? l : -1;
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < q; ++i) {
		cin >> k;
		cout << b_search1(0, n - 1) << ' ' << b_search2(0, n - 1) << endl;
	}

	return 0;
}
