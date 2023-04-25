#include <iostream>

#define MAXN 10007
#define MAXW 1007

using namespace std;

int n, W, Tsh, Tsm, Teh, Tem;
int w[MAXN], v[MAXN];
int f[MAXW];

void zeroOnePack(int wi, int vi) {
	for (int i = W; i >= wi; --i)
		f[i] = max(f[i], f[i - wi] + vi);
}

void completePack(int wi, int vi) {
	for (int i = wi; i <= W; ++i)
		f[i] = max(f[i], f[i - wi] + vi);
}

void multiplePack(int wi, int vi, int ci) {
	if (ci * wi >= W) {
		completePack(wi, vi);
		return;
	}
	int k = 1;
	while (k < ci) {
		zeroOnePack(k * wi, k * vi);
		ci -= k;
		k *= 2;
	}
	zeroOnePack(ci * wi, ci * vi);
}

int main() {
	char t;
	cin >> Tsh >> t >> Tsm >> Teh >> t >> Tem >> n;
	W = 60 * (Teh - Tsh) + (Tem - Tsm);
		
	for (int i = 0; i < n; ++i) {
		int wi, vi, ci;
		cin >> wi >> vi >> ci;
		if (ci == 0)
			completePack(wi, vi);
		else if (ci == 1)
			zeroOnePack(wi, vi);
		else
			multiplePack(wi, vi, ci);
	}
	cout << f[W] << endl;
	
	return 0;
}
