#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const ll mod = 1e9 + 7;

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

int main() {
    ll a, b;
    cin >> a >> b;
    a %= mod;
    b %= (mod - 1);
    cout << pow(a, b);
}
