#include <iostream>

using namespace std;

const int N = 100007;
int n, m, s[N], a[N];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int l, r;
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}

	return 0;
}
