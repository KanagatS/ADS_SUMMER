#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mod = 1e9 + 7;
int p = 31;

int get_hash(string s) {
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * p + (s[i] - 'a' + 1);
    }
    return h;
}

void rk(string s, string t, vector <bool> &a) {
    int n = s.length(), m = t.length();
    int hs = get_hash(s.substr(0, m));
    int ht = get_hash(t);
    int pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }
    for (int i = 0; i + m <= n; i++) {
        if (hs == ht) {
            for (int j = i; j < i + m; j++) {
                a[j] = true;
            }
        }
        if (i + m < n)
            hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
    }
}

int main() {
    string s; cin >> s;
    int n; cin >> n;
    vector <bool> check(s.size(), false);
    for (int i = 0; i < n; i++) {
        string sub; cin >> sub;
        rk(s, sub, check);
    }
    for (int i = 0; i < s.size(); i++) {
        if (!check[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}