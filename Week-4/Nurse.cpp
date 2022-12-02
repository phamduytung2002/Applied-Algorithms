#include <bits/stdc++.h>
using namespace std;

/*
    The director of a hospital want to schedule a working plan for
    a nurse in a given period of N consecutive days 1,..., N. Due
    to the policy of the hospital, each nurse cannot work all the
    days 1,..., N. Instead, there must be days off in which the nurse
    need to take a rest. A working plan is a sequence of disjoint
    working periods. A working period of a nurse is defined to be a
    sequence of consecutive days on which the nurse must work and the
    length of the working period is the number of consecutive days of
    that working period. The hospital imposes two constraints:
        i. Each nurse can take a rest only one day between two
        consecutive working periods. it means that if the nurse
        takes a rest today, then she has to work tomorrow
        ii. The length of each working period must be greater or equal
        to kmin and less than or equal to kmax
    The director of the hospital want to know how many possible working
    plans satisfying above constraint?
*/

typedef long long ll;
int n, kmin, kmax;
const ll mod = 1e9 + 7;

ll dp[1005];
// dp[i] = number of plans if day i and day 0 are off

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> kmin >> kmax;

    dp[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        for (int k = kmin; k <= kmax && k <= i - 1; ++k) {
            dp[i] = (dp[i] + dp[i - k - 1]) % mod;
        }
    }
    cout << dp[n - 1] + 2 * dp[n] + dp[n + 1];
    /*
        we have 4 cases:
        day 0 and day n+1 can be days off -> dp[n+1]
        day 1 and day n are days off -> dp[n-1]
        day 0 is a day off and day n is actually a day off -> dp[n]
        day 1 is a day off and day n+1 can be day off -> dp[n]
    */

    return 0;
}