#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int n, m, c, r;
queue<pii> q;
vector<vector<int>> maze(1000, vector<int>(1000, -1));
vector<vector<int>> dis(1000, vector<int>(1000, -1));

int add(int a, int b, int c, int d) {
    if (a < 0 || a >= n || b < 0 || b >= m) {
        return dis[c][d];
    } else if (maze[a][b] == 1 || dis[a][b] > -1)
        return 0;
    else {
        dis[a][b] = dis[c][d] + 1;
        q.push({a, b});
        return 0;
    }
}

int main() {
    cin >> n >> m >> c >> r;
    --c;
    --r;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    if (maze[c][r] == 1) {
        cout << -1;
        return 0;
    } else {
        q.push({c, r});
        dis[c][r] = 1;
        while (q.size() > 0) {
            pii top = q.front();
            c = top.first;
            r = top.second;
            q.pop();
            int ans = add(c + 1, r, c, r);
            ans = max(ans, add(c, r + 1, c, r));
            ans = max(ans, add(c - 1, r, c, r));
            ans = max(ans, add(c, r - 1, c, r));
            if (ans > 0) {
                cout << ans << endl;
                return 0;
            }
        }
        cout << -1;
    }
}