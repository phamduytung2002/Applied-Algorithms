#include <bits/stdc++.h>
using namespace std;

/*
    The Kingdom ALPHA has n warehouses of golds located on a straight
    line and are numbered 1, 2,..., n. The warehouse i has amount of ai >= 0
    and is located at coordinate i (i=1,...,n). The King of ALPHA opens
    a competition for hunters who are responsible to find a subset of
    gold warehouses having largest total amount of golds with respect to
    the condition that the distance between two selected warehouses must be
    greater than or equal to L1 and less than or equal to L2.
*/

int n, a[100001], lmin, lmax, dp[1000001], ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> lmin >> lmax;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        dp[i] = a[i];
        // some how 3/2 is enough to AC
        for (int l = lmin; l <= lmax && l <= i && l <= lmin * 3 / 2; ++l) {
            dp[i] = max(dp[i], a[i] + dp[i - l]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}