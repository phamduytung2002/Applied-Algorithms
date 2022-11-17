#include <bits/stdc++.h>
using namespace std;

// not done yet!

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second

ll H, W, n, h[11], w[11];

bool chk_size() {
    ll total_area = 0;
    ll HW = max(H, W);
    for (int i = 0; i < n; ++i) {
        if (h[i] > HW || w[i] > W) return false;
        total_area += h[i] * w[i];
    }
    if (total_area > H * W) return false;
    return true;
}

int main() {
    cin >> H >> W >> n;
    for (int i = 0; i < n; ++i) cin >> h[i] >> w[i];
    cout << chk_size();
}
