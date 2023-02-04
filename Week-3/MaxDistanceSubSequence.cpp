#include <bits/stdc++.h>
using namespace std;

/*
Given N elements (2≤ N ≤100,000) on a straight line at positions >=0, <=1e9
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.
*/

const int maxn = 100001;
const int maxx = 1000000000;
int n, c, x[maxn];

bool check(int d) {
    // check if there exist c points which pairwise distance is >= d
    int ind = 0;
    int num = 1;
    for (int i = 1; i < n; ++i) {
        if (x[i] - x[ind] >= d) {
            ind = i;
            ++num;
            if (num >= c) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        memset(x, 0, sizeof(x));
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        sort(x, x + n);

        int k = 1; // init low value of binary search
        // binary search on the answer k
        for (int b = maxx / 2; b >= 1; b /= 2) // b: jump step
            while (k + b <= x[n - 1] && check(k + b)) k += b;
        cout << k << endl; // k: max int st check(k) == true
    }
    
    return 0;
}