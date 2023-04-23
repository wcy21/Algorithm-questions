#include <iostream>

using namespace std;

int main() {
    int a, b, h;
    cin >> a >> b >> h;

    int now = a, cnt = 1;
    while (now < h) {
        now += a - b;
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}
