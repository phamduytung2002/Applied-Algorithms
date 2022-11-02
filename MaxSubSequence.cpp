#include <bits/stdc++.h>
using namespace std;

int n, a[1000001], dp[1000001][2], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp[0][0] = 0;
    dp[0][1] = a[0];
    ans = max(0, a[0]);
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = a[i] + max(0, dp[i - 1][1]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans;
}