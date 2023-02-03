#include <bits/stdc++.h>
using namespace std;

/*
    Given a sequence of distinct integers a1, a2, …, an
    and an integer Q. Count number M of pairs (i, j) 
    such that 1 ≤ i< j ≤ n and ai + aj = Q
*/

int n, q, a[1000005], res;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0, j = n - 1; i < j;) {
        if (a[i] + a[j] == q)
            ++res, ++i, --j;
        else if (a[i] + a[j] > q)
            --j;
        else
            ++i;
    }
    cout<<res;
}