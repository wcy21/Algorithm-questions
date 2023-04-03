#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	stack<pair<int, int>> st;
	int n, x, f[3000007];
	memset(f, 0, sizeof(f));
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		
		while (!st.empty() && st.top().first < x) {
			f[st.top().second] = i;
			st.pop();
		}
		st.push({x, i});
	}
	
	for (int i = 1; i <= n; ++i)
		cout << f[i] << ' ';
	
	return 0;
}
