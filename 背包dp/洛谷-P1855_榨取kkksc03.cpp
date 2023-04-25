#include <iostream>

using namespace std;

const int SIZE = 207;

int n, W, T;
int w[SIZE], t[SIZE];
int f[SIZE][SIZE];

int main() {
	cin >> n >> W >> T;
	for (int i = 0; i < n; ++i)
		cin >> w[i] >> t[i];

	for (int k = 0; k < n; ++k)
		for (int i = W; i >= w[k]; --i)
			for (int j = T; j >= t[k]; --j) 
				f[i][j] = max(f[i][j], f[i - w[k]][j - t[k]] + 1);

	cout << f[W][T] << endl;
	
	return 0;
}
