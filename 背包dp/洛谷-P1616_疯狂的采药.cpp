#include <iostream>

using namespace std;

int N, W;
int w[10007], v[10007];
long long f[10000007];

int main() {
	cin >> W >> N;
	for (int i = 0; i < N; ++i)
		cin >> w[i] >> v[i];
	
	for (int i = 0; i < N; ++i)
		for (int j = w[i]; j <= W; ++j)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	
	cout << f[W] << endl;

	return 0;
}
