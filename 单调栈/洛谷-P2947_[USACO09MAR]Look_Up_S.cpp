#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int MAXN =  1e5 + 7;

int main() {
	stack<PII> st;
	int N, x, f[MAXN];
	memset(f, 0, sizeof(f));
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> x;
		while (!st.empty() && st.top().second < x) {
			f[st.top().first] = i;
			st.pop();
		}
		st.push({i, x});
	}
	
	for (int i = 1; i <= N; ++i)
		cout << f[i] << endl;

	return 0;
}
