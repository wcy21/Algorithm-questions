#include <iostream>

using namespace std;

int main() {
	int t, n, a[200007], b[200007];
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n - 1; ++i)
			cin >> a[i];
		
		b[0] = a[0], b[n - 1] = a[n - 2];
		for (int i = 1; i < n - 1; ++i)
			b[i] = min(a[i - 1], a[i]);
		
		for (int i = 0; i < n; ++i)
			cout << b[i] << ' ';
		cout << endl;
	}

	return 0;
}
