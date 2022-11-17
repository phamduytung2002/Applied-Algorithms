#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second

int n, a[7], ans(0);

bool chk_ans() {
    int val = a[0] * 100 + a[1] * 10 + a[2] - 62 - a[3] * 100 + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[2];
    if (val == n) return true;
    return false;
}

bool chk_candidate(int k, int val) {
    for (int i = 0; i < k; ++i) {
        if (a[i] == val) return false;
    }
    return true;
}

void Try(int k) {
    for (int val = 1; val <= 9; ++val) {
        if (!chk_candidate(k, val)) continue;
        a[k] = val;
        if (k == 6) {
            if (chk_ans()) ++ans;
        } else {
            Try(k + 1);
        }
    }
}

int main() {
    cin >> n;

    Try(0);
    cout << ans;
}