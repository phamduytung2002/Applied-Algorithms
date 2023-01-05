#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> edges(100001, vector<int>(0));
int component[100001];
int num_comp = 0;

void dfs(int vertex) {
    if (component[vertex] != -1) return;
    component[vertex] = num_comp;
    for (int i = 0; i < edges[vertex].size(); ++i) {
        dfs(edges[vertex][i]);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) component[i] = -1;
    for (int i = 1; i <= n; ++i) {
        if (component[i] == -1) {
            ++num_comp;
            dfs(i);
        }
    }
    cout<<num_comp;
}