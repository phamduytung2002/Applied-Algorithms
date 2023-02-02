#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int n, m;
vector<vector<int>> edges(maxn, vector<int>(0));
int low[maxn], tin[maxn], cnt = 1;
bool visited[maxn];
stack<int> s;
int res = 0;

void dfs(int v) {
    // visited[v] = true;
    tin[v] = cnt;
    low[v] = cnt;
    ++cnt;
    for (int child : edges[v]) {
        if(visited[child]) continue;
        if (!tin[child]) {
            dfs(child);
            low[v] = min(low[v], low[child]);
        } else
            low[v] = min(low[v], tin[child]);
    }
    if (low[v] == tin[v]) {
        ++res;
        int u;
        do {
            u = s.top();
            s.pop();
            visited[u] = true;
        } while (u != v);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!tin[i]) {
            dfs(i);
        }
    }
    cout << res << endl;
    return 0;
}