#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

int A, B, c;
queue<pii> q;
map<pii, int> mov;

pii toB(pii x) {
    int sum = x.fi + x.se;
    if (sum < B)
        return {0, sum};
    else
        return {sum - B, B};
}

pii toA(pii x) {
    int sum = x.fi + x.se;
    if (sum < A)
        return {sum, 0};
    else
        return {A, sum - A};
}

pii addA(pii x) {
    return {A, x.se};
}

pii addB(pii x) {
    return {x.fi, B};
}

pii removeA(pii x) {
    return {0, x.se};
}

pii removeB(pii x) {
    return {x.fi, 0};
}

bool chk(pii x) {
    return (x.fi == c || x.se == c);
}

void add(pii x, int movv) {
    if (mov[x] == 0 || mov[x] >= movv) {
        mov[x] = movv;
        q.push(x);
    }
}

int main() {
    cin >> A >> B >> c;
    if (c % __gcd(A, B) != 0 || c > max(A, B)) {
        cout << -1;
        return 0;
    }
    q.push({0, 0});
    mov[{0, 0}] = 0;
    while (q.size() > 0) {
        pii top = q.front();
        q.pop();
        if (chk(top)) {
            cout << mov[top];
            return 0;
        } else {
            int movv = mov[top] + 1;
            add(removeA(top), movv);
            add(removeB(top), movv);
            if (top.fi < A) {
                add(toA(top), movv);
                add(addA(top), movv);
            }
            if (top.se < B) {
                add(toB(top), movv);
                add(addB(top), movv);
            }
        }
    }
}