#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> st;
	long long n, x, sum = 0;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;

		while (!st.empty() && st.top() <= x)
			st.pop();
		sum += st.size();
		st.push(x);
	}

	cout << sum << endl;
	
	return 0;
}
