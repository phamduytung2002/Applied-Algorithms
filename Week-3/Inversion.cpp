#include <bits/stdc++.h>
using namespace std;

// Count number of inversion pairs in a[0],..,a[n-1]

int n, a[1000001];
const int mod = 1e9 + 7;
int ans = 0;

int tmp[1000001];
void mergesort(int a[], int l, int r) {  // [l, r)
    if (l >= r - 1) return;
    int mid = (l + r) / 2;
    mergesort(a, l, mid);
    mergesort(a, mid, r);
    for (int inx = l, lid = l, rid = mid; inx < r;) {
        if (lid >= mid) {
            tmp[inx++] = a[rid++];
        } else if (rid >= r) {
            tmp[inx++] = a[lid++];
        } else if (a[lid] <= a[rid]) {
            tmp[inx++] = a[lid++];
        } else {
            tmp[inx++] = a[rid++];
            ans = (ans + (mid - lid)) % mod;
        }
    }
    for (int inx = l; inx < r; ++inx) {
        a[inx] = tmp[inx];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    mergesort(a, 0, n);
    cout << ans;
    return 0;
}