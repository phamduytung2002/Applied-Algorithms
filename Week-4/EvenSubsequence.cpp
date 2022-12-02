#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a[1000001], dp[1000001][2][2];
// dp[id][mod2][use a[id]?]

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp[0][a[0] % 2][1] = a[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0][0] = max(dp[i - 1][0][0], dp[i - 1][0][1]);
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1]);
        dp[i][0][1] = max((a[i] % 2 == 0 ? a[i] : LLONG_MIN), dp[i - 1][(100000000 + a[i]) % 2][1] + a[i]);
        dp[i][1][1] = max((a[i] % 2 != 0 ? a[i] : LLONG_MIN), dp[i - 1][(100000001 + a[i]) % 2][1] + a[i]);
    }
    ll ans = max(dp[n - 1][0][0], dp[n - 1][0][1]);
    if (ans == LLONG_MIN)
        cout << "NOT_FOUND";
    else
        cout << ans;
    return 0;
}