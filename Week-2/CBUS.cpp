#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int n, k, c[23][23], cur_k, routes[23], minc = INT_MAX;
int pickorserve[12];
int ans = INT_MAX, len = 0, t = 1;

void Try() {
    for (int i = 1; i <= n; ++i) {
        if (cur_k < k && pickorserve[i] == 0) {
            routes[t] = i;
            len += c[routes[t - 1]][i];
            if (len + (2 * n - t) * minc < ans) {
                ++t;
                pickorserve[i] = 1;
                ++cur_k;
                Try();
                --cur_k;
                pickorserve[i] = 0;
                --t;
            }
            len -= c[routes[t - 1]][i];
        } else if (pickorserve[i] == 1) {
            routes[t] = i + n;
            len += c[routes[t - 1]][i + n];
            if (len + (2 * n - t) * minc < ans) {
                if (t == 2 * n) {
                    ans = min(ans, len + c[routes[t]][0]);
                } else {
                    pickorserve[i] = 2;
                    --cur_k;
                    ++t;
                    Try();
                    --t;
                    ++cur_k;
                    pickorserve[i] = 1;
                }
            }
            len -= c[routes[t - 1]][i + n];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < 2 * n + 1; ++i) {
        for (int j = 0; j < 2 * n + 1; ++j) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            if (i != j) minc = min(minc, c[i][j]);
        }
    }
    Try();
    cout << ans;
}