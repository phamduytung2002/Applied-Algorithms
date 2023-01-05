#include <bits/stdc++.h>
using namespace std;
/*
    Given an undirected graph G = (V,E).
    Write a program to check if G is a Hamiltonian graph.
*/

/*
    https://en.wikipedia.org/wiki/Hamiltonian_path#Bondy%E2%80%93Chv%C3%A1tal_theorem
*/

const int maxn = 100;
int n, m;
vector<vector<int>> edges;
bool adj[maxn][maxn];
int deg[maxn];

bool check_Ore() {
    // Ore's Theorem (1960), of course not AC
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (!adj[i][j] && deg[i] + deg[j] < n) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        edges.clear();
        memset(adj, 0, sizeof(adj));
        memset(deg, 0, sizeof(deg));
        edges = vector<vector<int>>(maxn, vector<int>());
        for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
            deg[v1] += 1;
            deg[v2] += 1;
        }
        cout << check_Ore() << endl;
    }
}