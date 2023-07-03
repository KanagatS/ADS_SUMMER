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

int KMP (string hay) {
    int n = hay.size();
    vector <int> lps(n, 0);
    LPS(hay, n, lps);
    for (int i = 0; i < n; i++) {
        cout << lps[i] << " ";
    }
    return lps[n - 1];
}

int main() {
    string s; cin >> s;
    KMP(s);
//    cout << s.size() - KMP(s);
}