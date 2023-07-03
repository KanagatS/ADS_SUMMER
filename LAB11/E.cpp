#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > g(200000);
bool used[200000];
bool orig_used[200000];
vector <int> comp;

void dfs (int v) {
    used[v] = true;
    comp.push_back(v);
    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
}

int find_comps(int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        used[i] = orig_used[i];
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            comp.clear();
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u; cin >> v >> u ;
        g[--v].push_back(--u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        orig_used[i] = true;
        cout << find_comps(n) << '\n';
    }
}