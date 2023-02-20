#include <bits/stdc++.h>
using namespace std;

typedef int ll;
int i, j;
ll n, m, a[100001], ans(0);
ll st[400005];

void build(int id, int l, int r) {
    if (l > r)
        return;
    else if (l == r) {
        st[id] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        st[id] = max(st[2 * id], st[2 * id + 1]);
    }
}

ll get(int id, int u, int v, int l, int r) {
    // st[id] = max(a[u], a[u+1],..., a[v])
    // need to find max(a[l],..., a[r])
    if (r < u || l > v)
        return INT_MIN;
    else if (l <= u && r >= v)
        return st[id];
    else {
        int mid = (u + v) / 2;
        return max(get(2 * id, u, mid, l, r), get(2 * id + 1, mid + 1, v, l, r));
    }
}

void update(int id, int u, int v, int i, int val) {
    a[i] = val;
    if (u > i || v < i)
        return;
    else if (u == v)
        st[id] = val;
    else {
        int mid = (u + v) / 2;
        update(id * 2, u, mid, i, val);
        update(id * 2 + 1, mid + 1, v, i, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
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
        string s;
        cin >> s;
        if (s == "get-max") {
            cin >> i >> j;
            cout << rmq(i - 1, j - 1) << endl;
        } else {
            cin >> i >> j;
            update(1, 0, n - 1, i - 1, j);
        }
    }
}