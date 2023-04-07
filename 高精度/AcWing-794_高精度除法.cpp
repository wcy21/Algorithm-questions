#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> div(vector<int>& A, int b, int& r) {
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; --i) {
		r = 10 * r + A[i];
		C.push_back(r / b);
		r %= b;
	}

	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main() {
	string a;
	int b, r;
	cin >> a >> b;

	vector<int> A;
	for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');

	vector<int> ans = div(A, b, r);
	for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i];
	cout << endl << r;

	return 0;
}
