#include <bits/stdc++.h>
using namespace std;

/*
    Find the length of longest common subsequence of 2 sequence x and y
*/

int n, m, x[10001], y[10001], dp[10001][10001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= m; ++i) cin >> y[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (x[i] == y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}