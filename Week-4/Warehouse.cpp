#include <bits/stdc++.h>
using namespace std;

/*
    A truck is planned to arrive at some stations among N stations
    1, 2, . . ., N located on a line. Station i (i = 1,…,N) has coordinate
    i and has following information
        ai : amount of goods
        ti : pickup time duration for taking goods
    The route of the truck is a sequence of stations x1 < x2 < . . . < xk
    (1 ≤ xj ≤ N, j = 1,…, k). Due to technical constraints, the distance between
    two consecutive stations that the truck arrives xi and xi+1 is less than or
    equal to D and the total pickup time duration cannot exceed T. Find a route
    for the truck such that total amount of goods picked up is maximal.
*/

int N, T, D, a[1001], t[1001];
int dp[1001][101];
// dp[i][t] = weight if pickup with time t and last picked at i
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T >> D;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> t[i];

    for (int time = 0; time <= T; ++time) dp[0][time] = INT_MIN;
    for (int i = 0; i < N; ++i) dp[i][t[i]] = a[i];

    for (int i = 0; i < N; ++i) {
        for (int time = 0; time <= T; ++time) {
            for (int dist = 1; dist <= D; ++dist) {
                if (dist > i) break;
                if (t[i] > time) continue;
                dp[i][time] = max(dp[i][time], a[i] + dp[i - dist][time - t[i]]);
                ans = max(dp[i][time], ans);
            }
        }
    }
    cout << ans << endl;

    return 0;
}