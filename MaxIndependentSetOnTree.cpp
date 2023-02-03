#include <bits/stdc++.h>
using namespace std;

// brute force
/*
int n, w[21], tmp1, tmp2;
bool e[21][21];
bool subset[21];
int mis = 0;

bool check(int k) {
    for (int i = 0; i < k; ++i) {
        if (i == k) continue;
        if (e[k][i] && subset[i]) return false;
    }
    return true;
}

void Try(int k) {
    if (k == n) {
        int tmp_mis = 0;
        for (int i = 0; i < n; ++i) {
            if (subset[i]) tmp_mis += w[i];
        }
        mis = max(tmp_mis, mis);
        return;
    }
    subset[k] = 0;
    Try(k + 1);
    subset[k] = 1;
    if (check(k)) Try(k + 1);
}

int main() {
    memset(e, 0, sizeof(e));
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> tmp1 >> tmp2;
        e[tmp1 - 1][tmp2 - 1] = true;
        e[tmp2 - 1][tmp1 - 1] = true;
    }
    Try(0);
    cout << mis;
}*/

// dp on tree

const int maxn = 100001;
int n, w[maxn], tmp1, tmp2;
int parent[maxn], dp[maxn][2];
// dp[i][0]: mis of subtree root i without i in the independent set
// dp[i][1]: mis of subtree root i with i in the independent set
vector<vector<int>> edges(maxn, vector<int>());
int mis = 0;

void cal(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = w[u];
    for (int v : edges[u]) {
        if (v == p) continue;
        cal(v, u);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> tmp1 >> tmp2;
        edges[tmp1 - 1].push_back(tmp2 - 1);
        edges[tmp2 - 1].push_back(tmp1 - 1);
    }
    cal(0, -1);
    cout << max(dp[0][0], dp[0][1]);
}