#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int n, m;
vector<vector<int>> edges(maxn, vector<int>(0));
int low[maxn], tin[maxn], cnt = 1;
bool visited[maxn];
bool isAP[maxn];
int n_ap = 0;

void dfs(int v, int parent) {
    visited[v] = true;
    tin[v] = cnt;
    low[v] = cnt;
    ++cnt;
    int n_child = 0;
    for (int child : edges[v]) {
        if (child == parent) continue;
        if (!visited[child]) {
            dfs(child, v);
            low[v] = min(low[v], low[child]);
            if (low[child] >= tin[v] && parent != -1) isAP[v] = true;
            ++n_child;
        } else {
            low[v] = min(low[v], tin[child]);
        }
    }
    if (parent == -1 && n_child > 1) isAP[v] = true;
}

int num_articulation_point() {
    int res = 0;
    for (int i = 1; i <= n; ++i) res += isAP[i];
    return res;
}

int num_bridge() {
    int res = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v : edges[u]) {
            if (low[v] > tin[u]) ++res;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        edges[tmp1].push_back(tmp2);
        edges[tmp2].push_back(tmp1);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    cout << num_articulation_point() << " " << num_bridge();
}