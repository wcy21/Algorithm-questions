#include <iostream>
#define MAXN 1000007

using namespace std;

int n, k;
int a[MAXN], q[MAXN];

void get_min() {
	int head = 0, tail = 0;
	for (int i = 1; i < k; ++i) {
		while (head <= tail && a[q[tail]] >= a[i]) tail--;
		q[++tail] = i;
	}
	for (int i = k; i <= n; ++i) {
		while (head <= tail && a[q[tail]] >= a[i]) tail--;
		q[++tail] = i;
		while (q[head] <= i - k) head++;
		cout << a[q[head]] << ' ';
	}
	cout << '\n';
}

void get_max() {
	int head = 0, tail = 0;
	for (int i = 1; i < k; ++i) {
		while (head <= tail && a[q[tail]] <= a[i]) tail--;
		q[++tail] = i;
	}
	for (int i = k; i <= n; ++i) {
		while (head <= tail && a[q[tail]] <= a[i]) tail--;
		q[++tail] = i;
		while (q[head] <= i - k) head++;
		cout << a[q[head]] << ' ';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	get_min();	
	get_max();
	
	return 0;
}
