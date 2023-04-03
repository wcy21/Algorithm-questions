#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int n, x, a[107];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

	x = abs(a[1] - a[0]);
    for (int i = 1; i < n; ++i) 
    	x = gcd(x, abs(a[i] - a[i - 1]));
    	
    for (int i = 2; i * i <= x; ++i) {
    	if (x % i == 0) {
    		cout << i << ' ';
    		
    		if (i * i < x)
    			cout << x / i << ' ';
		}
	}
	cout << x << endl;

    return 0;
}
