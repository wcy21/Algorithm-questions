#include <iostream>
#include <cstring>

using namespace std;

int n, m[107];

bool valid() {
    int temp = 0;
    for (int i = 1; i <= 100; ++i)
        temp = (10 * temp + m[i]) % n;

    if (temp == 0)
        return true;
    return false;
}

void dfs(int i) {
    if (m[0] != 0) 
		return;
    if (i == 100) {
        if (valid()) {
            int idx = 1;
            while (idx <= 100 && m[idx] == '0') 
              idx += 1;
            while (idx <= 100) {
                cout << m[idx];
                idx += 1;
            }
            cout << endl;
            m[0] = 1;
        }
        return;
    }

    m[i] = 1;
    dfs(i + 1);

    m[i] = 0;
    dfs(i + 1);
}

int main() {
    while (cin >> n) {
        if (n == 0)
            break;

        memset(m, 0, sizeof(m));
        dfs(1);
    }

    return 0;
}
