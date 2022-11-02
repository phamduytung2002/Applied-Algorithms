#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int i, j;
ll n, m, a[1000001], ans(0);
ll st[4000005];

void build(int id, int l, int r) {
    if (l > r)
        return;
    else if (l == r) {
        st[id] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        st[id] = min(st[2 * id], st[2 * id + 1]);
    }
}

ll get(int id, int u, int v, int l, int r) {
    // st[id] = min(a[u], a[u+1],..., a[v])
    // need to find min(a[l],..., a[r])
    if (r < u || l > v)
        return INT_MAX;
    else if (l <= u && r >= v)
        return st[id];
    else {
        int mid = (u + v) / 2;
        return min(get(2 * id, u, mid, l, r), get(2 * id + 1, mid + 1, v, l, r));
    }
}

ll rmq(int i, int j) {
    return get(1, 0, n - 1, i, j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    cin >> m;   
    while (m--) {
        cin >> i >> j;
        ans += rmq(i, j);
    }
    cout << ans << endl;
}