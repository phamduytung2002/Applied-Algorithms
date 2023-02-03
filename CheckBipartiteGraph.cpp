#include <bits/stdc++.h>
using namespace std;

const int nmax = 100001;
int n, m, tmp1, tmp2;
vector<vector<int>> edges(nmax, vector<int>());

int part[nmax];
bool res = true;

void dfs(int u, int p) {
    for (int v : edges[u]) {
        if (v == p) continue;
        if (part[v] == part[u]) {
            res = false;
            return;
        } else if (part[v] == -1) {
            part[v] = 1 - part[u];
            dfs(v, u);
            if (!res) return;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmp1 >> tmp2;
        edges[tmp1 - 1].push_back(tmp2 - 1);
        edges[tmp2 - 1].push_back(tmp1 - 1);
    }
    for (int i = 0; i < n; ++i) part[i] = -1;
    for (int i = 0; i < n; ++i) {
        if (part[i] == -1) {
            part[i] = 0;
            dfs(i, -1);
        }
        if (!res) break;
    }
    if (res)
        cout << 1;
    else
        cout << 0;
}