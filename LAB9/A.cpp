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

bool KMP (string hay, string needle) {
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
            return true;
            // cout << i - j << " ";
            // j = lps[j - 1];
        }
    }
    return false;
}

int main() {
    string A; cin >> A;
    // string B; cin >> B;
    // int cnt = 0;
    // if (A == B) {
    //     cout << 1;
    //     return 0;
    // }
    // int rep = B.size()/A.size() + 2;
    // string tmp = "";
    // for (int i = 0; i < B.size()/A.size(); i++) {
    //     tmp += A;
    //     cnt++;
    // }
    // while (cnt <= rep) {
    //     if (KMP(tmp, B)) {
    //         cout << cnt;
    //         return 0;
    //     }
    //     tmp += A;
    //     cnt++;
    // }
    // cout << -1;
    vector <int> lps (A.size(), 0);
    LPS(A, A.size(), lps);
    for (int i = 0; i < A.size(); i++) {
        cout << lps[i] << ' ';
    }
}