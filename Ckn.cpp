#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll k, n, ans(1);

ll pow(ll x, ll ex) {
    if (ex == 0)
        return 1;
    else {
        ll t = pow(x, ex / 2);
        if (ex % 2 == 0)
            return (t * t) % mod;
        else
            return (t * ((t * x) % mod)) % mod;
    }
}

ll inv(ll x) {
    return pow(x, mod - 2);
}

int main() {
    cin >> k >> n;
    if (k > n) {
        cout << 0;
        return 0;
    } else {
        while (k > 0) {
            ans *= n--;
            ans %= mod;
            ans *= inv(k--);
            ans %= mod;
        }
        cout << ans;
    }
}
