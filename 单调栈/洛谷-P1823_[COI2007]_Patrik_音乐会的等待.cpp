#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	stack<pair<int, long long>> st;
	long long n, x, cnt, ans = 0;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		
		cnt = 1;
		while (!st.empty() && st.top().first <= x) {
			ans += st.top().second;
			if (st.top().first == x)
				cnt += st.top().second;

			st.pop();
		}
		if (!st.empty())
			ans += 1;
		
		st.push({x, cnt});
	}

	cout << ans << endl;
	
	return 0;
}
