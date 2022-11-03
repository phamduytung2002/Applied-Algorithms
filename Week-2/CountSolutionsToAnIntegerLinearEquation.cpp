#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, M, a[101], x[101];
ll ans = 0;

void Try(int k, int sum) {
    for (int i = 1; i <= (M - sum) / a[k]; ++i) {
        x[k] = i;
        sum += a[k] * x[k];
        if (sum <= M) {
            if (k == n - 1) {
                if (sum == M) ++ans;
            } else {
                Try(k + 1, sum);
            }
        }
        sum -= a[k] * x[k];
        x[k] = 0;
    }
}

int main() {
    cin >> n >> M;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Try(0, 0);
    cout << ans << endl;
}