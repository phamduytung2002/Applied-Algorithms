#include <bits/stdc++.h>
using namespace std;

int n, m, a[1000005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j) {
        if (a[i] + a[j] == m) {
            ++ans;
            ++i;
        } else if (a[i] + a[j] < m) {
            ++i;
        } else {
            --j;
        }
    }
    cout << ans << endl;
}