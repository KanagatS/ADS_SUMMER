#include <iostream>
#include <algorithm>

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

void rk(string s1, string s2, string t) {
    int n = s1.length(), k = s2.length(), m = t.length();
    int hs1 = get_hash(s1.substr(0, m));
    int hs2 = get_hash(s2.substr(0, m));
    int ht = get_hash(t);
    int pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }
    int cnt = 0;
    for (int i = 0; i + m <= n && i + m <= k; i++) {
        if (hs1 == ht && hs2 == ht)
            cnt++;
        if (i + m < n && i + m < k)
            hs1 = (hs1 - pm * (s1[i] - 'a' + 1)) * p + (s1[i + m] - 'a' + 1);
            hs2 = (hs2 - pm * (s2[i] - 'a' + 1)) * p + (s2[i + m] - 'a' + 1);
    }
    cout << cnt;
}

int main() {
    string s1, s2, t; cin >> s1 >> s2 >> t;
    rk(s1, s2, t);
}