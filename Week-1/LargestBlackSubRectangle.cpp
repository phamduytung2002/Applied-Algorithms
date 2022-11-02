#include <bits/stdc++.h>
using namespace std;

const int maxnm = 1005;
int n, m, a[maxnm][maxnm];
int ones_in_the_left[maxnm][maxnm];
#define fi first
#define se second

int solve(int j) {
    int l[maxnm], r[maxnm];
    for (int i = 0; i < n; ++i) {
        l[i] = i;
        r[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        while (l[i] > 0 && ones_in_the_left[i][j] <= ones_in_the_left[l[i] - 1][j]) {
            l[i] = l[l[l[i] - 1]];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        while (r[i] < n - 1 && ones_in_the_left[i][j] <= ones_in_the_left[r[i] + 1][j]) {
            r[i] = r[r[r[i] + 1]];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, ones_in_the_left[i][j] * (r[i] - l[i] + 1));
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == 1)
            ones_in_the_left[i][0] = 1;
        else
            ones_in_the_left[i][0] = 0;
        for (int j = 1; j < m; ++j) {
            if (a[i][j] == 1)
                ones_in_the_left[i][j] = ones_in_the_left[i][j - 1] + 1;
            else
                ones_in_the_left[i][j] = 0;
        }
    }
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        ans = max(ans, solve(j));
    }
    cout << ans << endl;
}