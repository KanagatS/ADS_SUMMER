#include <iostream>
#include <vector>

using namespace std;

pair <bool, int> dfs2(vector <vector <int> > &adj, vector <bool> &visited, int start, int end, int cnt, int path, bool &reached) {
    if (start == end) {
        reached = true;
        return make_pair(true, cnt);
    }
    cnt++;
    visited[start] = true;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            int res = dfs2(adj, visited, i, end, cnt, path, reached).second;
            path = min(path, res);
        }
    }
    return make_pair(reached, path);
}

void dfs(vector <vector <int> > &adj, vector <bool> &visited, int start, int end, int cnt, int path, bool reached) {
    pair <bool, int> tmp = dfs2(adj, visited, start, end, cnt, path, reached);
    if (tmp.first)
        cout << tmp.second;
    else
        cout << -1;
} 



int main() {
    int n; cin >> n;
    vector <vector <int> > adj(n, (vector <int> (n)));
    vector <bool> visited (n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    int start, end; cin >> start >> end;
    dfs(adj, visited, start - 1, end - 1, 0, INT32_MAX, false);
}