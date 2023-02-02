#include <bits/stdc++.h>
using namespace std;

int n, m, d[10001], t[10001];
vector<vector<int>> edges(10001, vector<int>(0));

void dfs(int i) {
    if (!t[i]) {
        for (int j : edges[i]) {
            dfs(j);
            t[i] = max(t[i], t[j]);
        }
        t[i] += d[i];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = 0; i < m; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        edges[tmp1-1].push_back(tmp2-1);
    }
    for (int i = 0; i < n; ++i) {
        if (!t[i]) dfs(i);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, t[i]);
    }
    cout << res;
}