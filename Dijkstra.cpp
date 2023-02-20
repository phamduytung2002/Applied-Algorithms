#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, m, s, t, dist[maxn];
bool visited[maxn];
vector<vector<pair<int, int>>> edges(maxn);

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        edges[tmp1].push_back({tmp2, tmp3});
    }
    cin >> s >> t;

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i <= n; ++i) dist[i] = 5e7;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int vertex = top.second;
        visited[vertex] = 1;
        for (auto i : edges[vertex]) {
            if (visited[i.first]) continue;
            int tmp = dist[vertex] + i.second;
            if (tmp < dist[i.first]) {
                pq.push({tmp, i.first});
                dist[i.first] = tmp;
            }
        }
    }
    cout << dist[t];
}