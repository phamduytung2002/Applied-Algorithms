#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

ll solve(string s) {
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans = (ans * 256 + s[i])%m;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}