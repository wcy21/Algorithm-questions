#include <iostream>
#include <cstring>

using namespace std;

int T, M;
int tcost[107], mget[107];
int mem[107][1007];

int dfs(int pos, int tleft) {
	if (mem[pos][tleft] != -1)
		return mem[pos][tleft];

	if (pos == M)
		return mem[pos][tleft] = 0;

	int dfs1, dfs2 = -1;
	dfs1 = dfs(pos + 1, tleft);
	if (tleft >= tcost[pos])
		dfs2 = dfs(pos + 1, tleft - tcost[pos]) + mget[pos];

	return mem[pos][tleft] = max(dfs1, dfs2);
}

int main() {
	memset(mem, -1, sizeof(mem));
	cin >> T >> M;
	for (int i = 0; i < M; ++i)
		cin >> tcost[i] >> mget[i];
    
	cout << dfs(0, T) << endl;

	return 0;
}
