#include <bits/stdc++.h>
using namespace std;

int n, tmp;
typedef long long ll;
const ll mod = 1e9 + 7;
ll ans = 0;

int main() {
    cin >> n;
    set<int> s;
    while (n--) {
        cin >> tmp;
        ans = ans + (s.end() - s.upper_bound(tmp));
        s.insert(tmp);
        ans %= mod;
    }
    cout << ans << endl;
}