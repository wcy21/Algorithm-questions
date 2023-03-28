#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int l, r;

    bool operator<(const node& x) const {
        return max(this->l * this->r, x.r) < max(this->r, x.l * x.r);
    }
} a[10007];

string toString(int num) {
    string ret;
    while (num) {
        ret.insert(0, 1, (num % 10 + '0'));
        num /= 10;
    }
    return ret;
}

string product(string x, string y) {
    string ret(x.size() + y.size(), 0);
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for (int i = 0; i < x.size(); ++i) {
        for (int j = 0; j < y.size(); ++j)
            ret[i + j] += (x[i] - '0') * (y[j] - '0');
        for (int j = 0; j < i + y.size(); ++j) {
            ret[j + 1] += ret[j] / 10;
            ret[j] = ret[j] % 10;
        }
    }
    for (int i = 0; i < ret.size(); ++i)
        ret[i] += '0';
    reverse(ret.begin(), ret.end());
    ret.erase(0, ret.find_first_not_of('0'));
    return ret.empty() ? "0" : ret;
}

string quotient(string x, int y) {
    string ret;
    int temp = 0;
    for (int i = 0; i < x.size(); ++i) {
        temp = 10 * temp + x[i] - '0';
        ret += temp / y + '0';
        temp %= y;
    }
    ret.erase(0, ret.find_first_not_of('0'));
    return ret.empty() ? "0" : ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + n + 1);

    string ans, tmp;
    string prod = toString(a[0].l);
    for (int i = 1; i <= n; ++i) {
        tmp = quotient(prod, a[i].r);
        if (tmp.size() > ans.size() || (tmp.size() == ans.size() && tmp > ans))
            ans = tmp;
        prod = product(toString(a[i].l), prod);
    }
    cout << ans << endl;

    return 0;
}
