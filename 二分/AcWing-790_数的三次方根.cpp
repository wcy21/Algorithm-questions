#include <iostream>
#include <iomanip>

using namespace std;

double n;

double b_search3(double l, double r) {
	const double eps = 1e-7;
	while (r - l > eps) {
		double mid = (l + r) / 2;
		if (mid * mid * mid <= n) l = mid;
		else r = mid;
	}
	return l;
}

int main() {
	cin >> n;
	cout << fixed << setprecision(6) << b_search3(-10000.0, 10000.0);

	return 0;
}
