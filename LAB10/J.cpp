#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector <vector <int> > g(n);
    vector <vector <int> > parents(n);
    vector <bool> visited (n, false);
    vector <int> degree(n, 0);
    while(m--) {
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        parents[b - 1].push_back(a - 1);
        degree[b - 1]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        if (degree[i] == 0) {
            cnt++;
        }
        else {
            bool ok = true;
            for (int j = 0; j < parents[i].size(); j++) {
                if (g[i].size() <= g[parents[i][j]].size())
                    ok = false;
                // cout << "\ndegree of: " << i << " " << degree[i] << " parents degrees " << degree[parents[i][j]];
            }
            if (ok)
                cnt++;
        }
    }
    cout << cnt;
}