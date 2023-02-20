#include <bits/stdc++.h>

using namespace std;

const int maxN = 100010;

int n, m;
int timeDfs = 0, scc = 0;
int low[maxN], num[maxN];
bool deleted[maxN];
vector <int> g[maxN];
stack <int> st;

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (int v : g[u]) {
    	if (deleted[v]) continue;
        if (!num[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        scc++;
        int v;
        do {
            v = st.top(); 
            st.pop();
            deleted[v] = true;
        }
        while (v != u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i);

    cout << scc;
}