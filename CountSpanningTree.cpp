#include <bits/stdc++.h>
using namespace std;

/*
    Given a undirected connected graph G = (V,E) in
    which V = {1,…,N} is the set of nodes and E is the
    set of M edges. Count the number of spanning trees of G.
*/

typedef pair<int, int> pii;
#define fi first
#define se second
const int nmax = 40;
int n, m, res = 0, n_edges = 0, n_visit = 0;
bool visited[nmax];
vector<pii> edges(0);
vector<vector<int>> e(nmax, vector<int>(0));

bool dfs_loop(int u, int p) {
    // return true if there is a loop
    memset(visited, 0, sizeof(visited));
    if (visited[u]) return true;
    visited[u] = true;
    n_visit++;
    for (int v : e[u]) {
        if (v == p) continue;
        if (dfs_loop(v, u)) return true;
    }
    return false;
}

void Try(int k) {
    if (k == m) {
        n_visit = 0;
        dfs_loop(0, -1);
        if (n_visit == n)
            res++;
    } else if (n_edges + (m - k) < n - 1 || n_edges >= n) {
        return;
    } else {
        cout << "k: " << k << endl;
        // not choose edge k
        Try(k + 1);
        // choose edge k
        e[edges[k].fi].push_back(edges[k].se);
        e[edges[k].se].push_back(edges[k].fi);
        ++n_edges;
        if (!dfs_loop(0, -1)) Try(k + 1);
        e[edges[k].fi].pop_back();
        e[edges[k].se].pop_back();
        --n_edges;
    }
}

int main() {
    cin >> n >> m;
    int tmp1, tmp2;
    for (int i = 0; i < m; ++i) {
        cin >> tmp1 >> tmp2;
        edges.push_back({tmp1 - 1, tmp2 - 1});
    }
    Try(0);
    cout << res;
}