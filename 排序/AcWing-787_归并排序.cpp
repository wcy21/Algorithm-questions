#include <iostream>

using namespace std;

int n, a[100007], tmp[100007];

void merge_sort(int q[], int l, int r) {
	if (l >= r) return;

	int mid = l + r >> 1;
	merge_sort(q, l, mid);
	merge_sort(q, mid + 1, r);

	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];

	for (i = l, j = 0; i <= r; ++i, ++j)
		q[i] = tmp[j];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	merge_sort(a, 0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';

	return 0;
}
