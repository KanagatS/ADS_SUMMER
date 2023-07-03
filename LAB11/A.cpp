#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector <int> p (200000);
int answer[200000];

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void process_query (int l, int r, int c) {
	for (int v = l; ; ) {
        if (c > answer[v])
		    v = dsu_get(v);
		if (v >= r)  break;
		
        if (c > answer[v])
		    p[v] = v+1;
        else
            v++;
        answer[v] = c;
	}
}

void dsu_unite (int a, int b) {
	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}

int main() {
    int n, m; cin >> n >> m;
    vector <pair <int, pair <int,int> > > g;
    queue <pair <int, pair <int,int> > > st;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++) {
        int l, r, c; cin >> l >> r >> c;
        st.push(make_pair(c, make_pair(--l, --r)));
        // g.push_back(make_pair(c, make_pair(--l, --r)));
        // for (int j = 0; j < r - l; j++) {
        //     g.push_back(make_pair(c, make_pair(l + j, l + j + 1)));
        // }
    }
    for (int i = 0; i < m; i++) {
        process_query(st.front().second.first, st.front().second.second, st.front().first);
        st.pop();
    }
    // int k = g.size();
    // for (int i = 0; i < k; i++)
    //     cout << g[i].first << ' ' << g[i].second.first << ' ' << g[i].second.second << '\n';
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
        cost += answer[i];
    }
    // sort(g.begin(), g.end());
    // p.resize(n);
    // for (int i = 0; i < n; i++)
    //     p[i] = i;
    // for (int i = 0; i < k; i++) {
    //     int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
    //     if (dsu_get(a) != dsu_get(b)) {
    //         cost += l;
    //         dsu_unite(a, b);
    //     }
    // }
    cout << cost;
}