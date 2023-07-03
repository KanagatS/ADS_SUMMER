#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

long long mod = 1e32 + 7;
long long p = 31;

unordered_set <long long> res;

long long get_hash(string s) {
    long long h = 0;
    for (long long i = 0; i < s.size(); i++) {
        h = (h * p + (s[i] - 'a' + 1));
    }
    return h;
}

void rk(string s) {
    long long n = s.length();
    long long hs = get_hash(s);
    long long pm = 1;
    for (long long i = 0; i < n - 1; i++) {
        pm *= p;
    }
    long long pg = 1;
    for (long long i = 0; i < n; i++) {
        long long pt = pg;
        long long ht = hs;
        res.insert(ht);
        for (long long j = n - 1; j > i; j--) {
            ht -= ((s[j] - 'a' + 1) * pt);
            pt *= p;
            res.insert(ht);
        }
        hs = ((hs - pm * (s[i] - 'a' + 1)) * p);
        pg *= p;
    }
}

void rk2(string s) {
    long long n = s.length();
    unordered_set <long long> d;
    for (long long i = 0; i < n; i++) {
        long long hs = 0;
        for (long long j = i; j < n; j++) {
            hs = (hs * p + (s[j] - 'a' + 1));
            d.insert(hs);
        }
    }
    cout << d.size();
}

int main() {
    string s; cin >> s;
    rk(s);
    cout << res.size();
}