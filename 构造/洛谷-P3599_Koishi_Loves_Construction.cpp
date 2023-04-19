#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

bool is_prime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= n / i; i += 2)
		if (n % i == 0) return false;
	return true;
}

ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	while (n) {
		if (n & 1)
			ret = ret * a % mod;
		
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

int main() {
	int X, T, n;
	cin >> X >> T;

	if (X == 1) {
		while (T--) {
			cin >> n;

			if (n != 1 && n & 1)
				cout << 0;
			else {
				cout << 2;
				for (int i = 0; i < n; ++i)
					cout << ' ' << (i & 1 ? i : n - i);
			}
			cout << endl;
		}
	}
	else {
		while (T--) {
			cin >> n;

			if (n > 4 && !is_prime(n))
				cout << 0;
			else {
				cout << 2;
        
				if (n == 4)
					cout << " 1 3 2 4";
				else {
					long long tmp = 1, pro = 1;
					for (long long i = 0; i < n - 1; ++i) {
						tmp = (i + 1) * mod_pow(pro, n - 2, n) % n;
						pro = pro * tmp % n;
						cout << ' ' << tmp;
					}
					cout << ' ' << n;
				}
			}
			cout << endl;
		}
	}

	return 0;
}
