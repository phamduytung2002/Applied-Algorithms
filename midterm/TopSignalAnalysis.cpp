#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second

const int maxn = 1000005;
int a[maxn], n;

int main() {
    cin >> n;
    int sol = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i + 1] && a[i] > a[i - 1]) ++sol;
    }
    cout<<sol;
}