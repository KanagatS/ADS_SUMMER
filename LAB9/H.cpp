#include <iostream>
#include <vector>
#include <math.h>

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

bool check (string s, int m) {
    int i = 0;
    string ref = s;
    for (int j = 0; j < m; j++) {
        s += s[i++];
    }
    if (s.substr(m, s.size()) == ref)
        return true;
    return false;
}

void KMP (string hay) {
    int n = hay.size();
    vector <int> lps(n, 0);
    LPS(hay, n, lps);
    int j = 0, i = 1, cnt = 0;
    bool ok = true;
    while (i < n) {
        // из нулей представим сабстринг который еще не встречался по ходу стринга
        // ставим j на последний встреченный 0, чтобы проверить совпадает ли длина префикса
        // из невстреченного сабстринга с суффиксом
        if (lps[i] == 0) {
            if (ok)
                j++;
            else
                j = i;
            ok = true;
        }
        // если есть совпадение, то учитываем вариант разделения стринга на 3 части
        // также проверяем на оверлап, если он есть, то этот варинт не в счет
        else if (j + 1 == lps[i] || (lps[i] % 2 == 0 && ((lps[i]/2) % (j + 1)) == 0)) {
            ok = false;
            cnt++;
        }
        i++;
    }
    // проверяем если весь стринг состоит из сабстринга на который указывает j
    if (j != n - 1 && check(hay, j + 1))
        cnt--;
    cout << cnt;
}

int main() {
    string s; cin >> s;
    if (s.size() < 3) {
        cout << 0;
        return 0;
    }
    KMP(s);
}