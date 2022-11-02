#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

int n;

bool visited[100005];
vector<vector<pii>> edges(100005, vector<pii>(0));
pii dfs(int v, int p) {
    pii farthest = {v, 0};
    for (auto x : edges[v]) {
        if (x.fi == p) continue;
        pii d = dfs(x.fi, v);
        if (x.se + d.se>farthest.se){
            farthest = {d.fi, d.se+x.se};
        }
    }
    return farthest;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    pii f = dfs(2, 0);
    f = dfs(f.fi, -1);
    cout<<f.se;
}