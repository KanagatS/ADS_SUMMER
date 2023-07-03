#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

long long mod = 1e9 + 7;
long long p = 11;

string get_hash(string s) {
    long long h = 0;
    for (long long i = s.size() - 1; i >= 0; i--) {
        h = (h * p % mod + (s[i] - 47)) % mod;
    }
    return to_string(h);
}

int main() {
    long long n; cin >> n;
    set <string> hashes;
    pair <string, string> a[2 * n];
    pair <string, string> answer[n];
    for (long long i = 0; i < 2 * n; i++) {
        string s; cin >> s;
        a[i].first = get_hash(s);
        a[i].second = s;
        hashes.insert(s);
    }
    int j = 0;
    for (long long i = 0; i < 2 * n; i++) {
        set <string> :: iterator it = hashes.find(a[i].first);
        if (it != hashes.end()) {
            cout << "Hash of string \"" << a[i].second << "\" is " << a[i].first << "\n";
            j++;
            if (j == n)
                break;
        }
    }
}