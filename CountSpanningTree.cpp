#include <bits/stdc++.h>
using namespace std;

/*
    Given a undirected connected graph G = (V,E) in
    which V = {1,…,N} is the set of nodes and E is the
    set of M edges. Count the number of spanning trees of G.
*/

// ref https://en.wikipedia.org/wiki/Kirchhoff%27s_theorem

#include <iostream>
#define N 30
using namespace std;

int n, m, tmp1, tmp2;
double e[N][N], deg[N];  // need to be double to calculate determinant

int determinantOfMatrix(double a[N][N], int t) {
    // copied from https://cp-algorithms.com/linear_algebra/determinant-gauss.html#algorithm
    const double EPS = 1E-9;
    double det = 1;

    for (int i = 0; i < t; ++i) {
        int k = i;
        for (int j = i + 1; j < t; ++j)
            if (abs(a[j][i]) > abs(a[k][i]))
                k = j;
        if (abs(a[k][i]) < EPS) {
            det = 0;
            break;
        }
        swap(a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j = i + 1; j < t; ++j)
            a[i][j] /= a[i][i];
        for (int j = 0; j < t; ++j)
            if (j != i && abs(a[j][i]) > EPS)
                for (int k = i + 1; k < t; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }

    return det;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmp1 >> tmp2;
        --tmp1;
        --tmp2;
        e[tmp1][tmp2] = -1;
        e[tmp2][tmp1] = -1;
        ++deg[tmp1];
        ++deg[tmp2];
    }
    for (int i = 0; i < n; ++i) {
        e[i][i] = deg[i];
    }
    cout << determinantOfMatrix(e, n - 1);
    return 0;
}

/*
// brute force, not finished yet
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

*/
