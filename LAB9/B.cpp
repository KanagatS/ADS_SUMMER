#include <iostream>
#include <vector>

using namespace std;

void LPS (string hay, int m, vector<int> &lps) {
    int len = 0;
    int i = 1;
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

void KMP (string hay, string needle, int k) {
    int n = hay.size();
    int m = needle.size();
    vector <int> lps(m, 0);
    LPS(hay, m, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (hay[i] == needle[j]) {
            j++;
            i++;
        }
        else if (j != 0) {
            j = lps[j - 1];
        }
        else {
            i++;
        }
        if (j == m) {
            k--;
            j = lps[j - 1];
            if (k == 0) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}

int main() {
    string s; cin >> s;
    int k; cin >> k;
    string t; cin >> t;
    KMP(t, s, k);
}