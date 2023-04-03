#include <iostream>
#include <cstring>
#include <stack>

#define MAXN 1000007

using namespace std;

int main() {
	stack<int> st;
	int n, ans = 0;
	int h[MAXN], v[MAXN], sum[MAXN];
	memset(sum, 0, sizeof(sum));
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h[i] >> v[i];
		
		while (!st.empty() && h[st.top()] < h[i]) {
			sum[i] += v[st.top()];
			st.pop();
		}
		if (!st.empty())
			sum[st.top()] += v[i];
				
		st.push(i);
	}
	for (int i = 0; i < n; ++i)
		ans = max(ans, sum[i]);

	cout << ans << endl;
	
	return 0;
}
