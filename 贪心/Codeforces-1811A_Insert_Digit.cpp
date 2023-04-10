#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, d;
		string s;

		cin >> n >> d >> s;
		int pos = 0;
		while (true) {
			while (pos < n && s[pos] >= d + '0') pos += 1;
			if (s[pos] < d + '0') break;
			pos += 1;
		}

		s.insert(pos, 1, d + '0');
		cout << s << endl;
	}

	return 0;
}
