#include <bits/stdc++.h>
using namespace std;

// alg from https://vnoi.info/wiki/translate/topcoder/max-flow-1-luong-cuc-dai-tren-mang-1.md

const int maxn = 1001;
int f[maxn][maxn], c[maxn][maxn];  // need to be adj mat
int n, m, source, sink, tmp1, tmp2;
bool visited[maxn];
int trace[maxn];

void bfs(int source, int sink) {
    memset(visited, 0, sizeof(visited));
    memset(trace, 0, sizeof(trace));
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && f[u][v] < c[u][v]) {
                q.push(v);
                visited[v] = true;
                trace[v] = u;
            }
            if (visited[sink]) return;
        }
    }
}

    bool existAugPath(int source, int sink) {
    bfs(source, sink);
    return visited[sink];  // if there is a path from source to sink
}

void increaseFlow(int source, int sink) {
    int minCapacity = INT_MAX;
    int v = sink;
    int prev = -1;
    while (v != source) {
        // find minCapacity
        prev = trace[v];
        minCapacity = min(minCapacity, c[prev][v] - f[prev][v]);
        v = prev;
    }
    v = sink;
    while (v != source) {
        // increase flow here
        prev = trace[v];
        f[prev][v] += minCapacity;
        f[v][prev] -= minCapacity;
        v = prev;
    }
}

int main() {
    cin >> n >> m >> source >> sink;
    memset(f, 0, sizeof(f));
    for (int i = 0; i < m; ++i) {
        cin >> tmp1 >> tmp2;
        cin >> c[tmp1][tmp2];
    }
    while (existAugPath(source, sink)) {
        increaseFlow(source, sink);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += f[source][i];
    }
    cout << res;
}