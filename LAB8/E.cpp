#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    long long prev = 0, p = 1;
    string res = "";
    for (int i = 0; i < n; i++) {
        long long cur; cin >> cur;
        char c = (cur - prev) / p + 97;
        res += c;
        prev = cur;
        p *= 2;
    }
    cout << res;
}