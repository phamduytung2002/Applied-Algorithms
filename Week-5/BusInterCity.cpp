#include <bits/stdc++.h>
using namespace std;

const int maxn = 5001;
const int maxm = 10001;
int n, m;
vector<vector<int>> edges(maxn, vector<int>(0));
int cost[maxn][maxn];
int c[maxn], d[maxn];
bool visited[maxn];

void dfs(int root, int maxd, int u, int p, int depth) {
    if (depth >= maxd)
        return;
    for (int v : edges[u]) {
        if (v == p || visited[v]) continue;
        visited[v] = 1;
        cost[root][v] = c[root];
        dfs(root, maxd, v, u, depth + 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> c[i] >> d[i];
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    for (int i = 1; i <= n; ++i) {
        memset(visited, 0, sizeof(visited));
        for (int j = 1; j <= n; ++j) cost[i][j] = INT_MAX - 5e7;
        dfs(i, d[i], i, -1, 0);
    }

    // Dijkstra's alg
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i <= n; ++i) c[i] = 5e7;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    c[1] = 0;
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int vertex = top.second;
        visited[vertex] = 1;
        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;
            int tmp = c[vertex] + cost[vertex][i];
            if (tmp < c[i]) {
                pq.push({tmp, i});
                c[i] = tmp;
            }
        }
    }
    cout << c[n];
}