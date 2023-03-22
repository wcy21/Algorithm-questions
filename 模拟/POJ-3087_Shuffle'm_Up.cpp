#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, C;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        string s1, s2, target;
        cin >> C >> s1 >> s2 >> target;

        set<string> state;
        int cnt = 0;
        while (true) {
            string s12;
            for (int i = 0; i < C; ++i) {
                s12.push_back(s2[i]);
                s12.push_back(s1[i]);
            }
            cnt += 1;

            if (s12 == target)
                break;

            if (state.count(s12)) {
                cnt = -1;
                break;
            }
            else
                state.insert(s12);
            
            s1 = s12.substr(0, C);
            s2 = s12.substr(C, C);
        }
        cout << i << ' ' << cnt << endl;
    }

    return 0;
}
