#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
string P, T;

int ans = 0;
ll infmod = ll(1e5) * mod;

ll hashString(string s, ll m) {
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans = (ans * 256 + ll(s[i])) % m;
    }
    return ans;
}

int main() {
    getline(cin, P);
    getline(cin, T);

    ll hashP = hashString(P, mod);

    ll hashT = ll(T[0]);
    ll hs = 1;
    for (int i = 1; i < P.size(); ++i) {
        hashT = (256 * hashT + ll(T[i])) % mod;
        hs = (hs * 256) % mod;
    }
    if (hashT == hashP) ans += 1;

    for (int i = P.size(); i < T.size(); ++i) {
        hashT = (hashT - hs * T[i - P.size()] + infmod) % mod;
        hashT = (hashT * 256 + ll(T[i])) % mod;
        if (hashT == hashP) ans += 1;
    }
    cout << ans;
}