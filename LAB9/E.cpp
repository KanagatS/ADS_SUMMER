#include <iostream>
#include <vector>

using namespace std;

void LPS (string hay, long long m, vector<long long> &lps) {
    long long len = 0;
    long long i = 1;
    while (i < m) {
        if (hay[i] == hay[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
}

long long KMP (string sub, long long k) {
    long long n = sub.size();
    vector <long long> lps(n, 0);
    LPS(sub, n, lps);
    long long size = (n - lps[n - 1]) * (k - 1) + n;
    return size;
}

int main() {
    long long q; cin >> q;
    while (q--) {
        string s; cin >> s;
        long long k; cin >> k;
        cout << KMP(s, k) << '\n';
    }
}