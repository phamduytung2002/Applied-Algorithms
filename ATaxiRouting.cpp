#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

void debug(function<void()> t) {
#ifdef DEBUG
    cout << "\n*****DEBUG*****\n";
    t();
    cout << "\n************endDEBUG************\n";
#endif
}

bool visited[12];
int n, c[25][25], x[15], d[15][15];
int dist = 0, ans = INT_MAX;
int min_edge = INT_MAX, min_to_depot = INT_MAX;

void Try(int k) {
    debug([=] { cout << k << ":" << dist << endl; });
    if (k == n + 1) {
        dist += d[x[n]][0];
        if (dist < ans) ans = dist;
        dist -= d[x[n]][0];
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        x[k] = i;
        dist += d[x[k - 1]][x[k]];
        if (dist + min_edge * (n - k) + min_to_depot < ans)
            Try(k + 1);
        dist -= d[x[k - 1]][x[k]];
        visited[i] = false;
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef OFFLINE
    const string test_name = argv[1];
    freopen((test_name).c_str(), "r", stdin);
    freopen((test_name + ".out").c_str(), "w", stdout);
#endif

    cin >> n;
    for (int i = 0; i < (n << 1 | 1); ++i)
        for (int j = 0; j < (n << 1 | 1); ++j)
            cin >> c[i][j];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            d[i][j] = c[i + n][j] + c[j][j + n];
            min_edge = min(min_edge, d[i][j]);
        }
        d[i][0] = c[i + n][0];
        d[0][i] = c[0][i] + c[i][i + n];
        min_to_depot = min(min_to_depot, d[i][0]);
    }

    Try(1);

    cout << ans;

    return 0;
}