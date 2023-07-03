#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector <vector <int> > g, queue <pair <int, int> > q, int n, int m, int num, int twos) {
    vector <vector <bool> > visited(n, vector<bool> (m, false));
    visited[q.front().first][q.front().second] = true;
    int cnt = 0;
    while(!q.empty()) {
        int tmp = 0;
        bool ok = false;
        while(twos--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i - 1 >= 0 && g[i - 1][j] == 1 && visited[i - 1][j] == false) {
                ok = true;
                visited[i - 1][j] = true;
                q.push(make_pair(i - 1, j));
                tmp++;
                num--;
            }
            if (j - 1 >= 0 && g[i][j - 1] == 1 && visited[i][j - 1] == false) {
                ok = true;
                visited[i][j - 1] = true;
                q.push(make_pair(i, j - 1));
                tmp++;
                num--;
            }
            if (i + 1 < n && g[i + 1][j] == 1 && visited[i + 1][j] == false) {
                ok = true;
                visited[i + 1][j] = true;
                q.push(make_pair(i + 1, j));
                tmp++;
                num--;
            }
            if (j + 1 < m && g[i][j + 1] == 1 && visited[i][j + 1] == false) {
                ok = true;
                visited[i][j + 1] = true;
                q.push(make_pair(i, j + 1));
                tmp++;
                num--;
            }
        }
        if (ok)
            cnt++;
        twos = tmp;
    }
    if (num == 0)
        cout << cnt;
    else
        cout << -1;
}

int main() {
    int n, m; cin >> n >> m;
    vector <vector <int> > g (n, vector<int> (m));
    queue <pair <int, int> > q;
    int num = 0;
    int twos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                q.push(make_pair(i, j));
                twos++;
            }
            if (g[i][j] == 1)
                num++;
        }
    }
    // cout << twos << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    if (num == 0) {
        cout << 0;
        return 0;
    }
    bfs(g, q, n, m, num, twos);
}