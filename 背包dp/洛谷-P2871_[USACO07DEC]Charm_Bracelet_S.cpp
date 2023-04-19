#include <iostream>

using namespace std;

int N, W;
int w[3507], v[3507];
int f[13007];

int main() {
	cin >> N >> W;
	for (int i = 0; i < N; ++i)
		cin >> w[i] >> v[i];
	
	for (int i = 0; i < N; ++i)
		for (int j = W; j >= w[i]; --j)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	
	cout << f[W] << endl;

	return 0;
}
