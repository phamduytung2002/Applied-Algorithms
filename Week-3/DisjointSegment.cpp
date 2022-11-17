#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

const int maxn = 1e5 + 5;
int n;
pii seg[maxn];
int dp[maxn];  // dp[i]: #maximal disjoint segments among the segments with index in {i...n-1}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seg[i].fi >> seg[i].se;
    }
    sort(seg, seg + n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        int a = lower_bound(seg, seg + n, make_pair(seg[i].se + 1, -1)) - seg;
        dp[i] = max(dp[i + 1], 1 + dp[a]);
    }
    cout << dp[0];
}