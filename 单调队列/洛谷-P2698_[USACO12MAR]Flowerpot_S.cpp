#include <iostream>
#include <algorithm>

#define MAXN 100007
#define INF 0x3f3f3f3f

using namespace std;

struct node {
	int x, y;

	bool operator<(const node& n) {
		return this->x < n.x;
	}
} a[MAXN];

int maxq[MAXN], minq[MAXN];
int lmax = 1, rmax = 0, lmin = 1, rmin = 0;
int N, D, L = 1, ans = INF;

int main() {
	cin >> N >> D;
	for (int i = 1; i <= N; ++i)
		cin >> a[i].x >> a[i].y;

	sort(a + 1, a + N + 1);

	for (int i = 1; i <= N; ++i) {
		while (lmax <= rmax && a[maxq[rmax]].y < a[i].y) rmax--;
		maxq[++rmax] = i;
		while (lmin <= rmin && a[minq[rmin]].y > a[i].y) rmin--;
		minq[++rmin] = i;
		while (L <= i && a[maxq[lmax]].y - a[minq[lmin]].y >= D) {
			ans = min(ans, a[i].x - a[L].x);
			L++;
			while (lmax <= rmax && maxq[lmax] < L) lmax++;
			while (lmin <= rmin && minq[lmin] < L) lmin++;
		}
	}

	if (ans != INF)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}
