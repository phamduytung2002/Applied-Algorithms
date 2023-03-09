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

#define fi first
#define se second

int n, m, x[1001], d[1001][1001];
bool pre[1001][1001];
map<pair<int, int>, bool> bef;

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
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        pre[tmp1][tmp2] = 1;
    }

    int cost = d[x[n - 1]][x[0]];
    for (int i = 0; i < n - 1; ++i) cost += d[x[i]][x[i + 1]];

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pre[x[j]][x[i]]) {
                cost = -1;
                break;
            }
        }
    }
    cout << cost;

    return 0;
}