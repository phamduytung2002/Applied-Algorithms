/*
    number of subset of arr a have sum >= A and <= B
*/

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
#define el << "\n"
#define sp << " "
#define sps << " " <<

bool offline(false), debug(false);

void DEBUG(function<void()> t) {
    if (debug && offline) {
        cout << "\n*****DEBUG*****\n";
        t();
        cout << "\n************endDEBUG************\n";
    }
}

void preprocess(int argc, char** argv) {
    if (argc > 2) {
        string s = argv[1];
        if ((s[0] - 'a') % 2 == 0) {
            offline = true;
            const string test_name = argv[2];
            freopen((test_name).c_str(), "r", stdin);
            freopen((test_name + ".out").c_str(), "w", stdout);
        }
        if ((s[0] - 'a') / 2 % 2 == 0) {
            debug = true;
        }
    }
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int maxn = 21;
int n, A, B, a[maxn], res = 0;
int sum = 0;

bool take[21];

void Try(int k) {
    if (k == n) {
        if (sum >= A) ++res;
        return;
    }
    take[k] = false;
    Try(k + 1);

    take[k] = true;
    sum += a[k];
    if (sum <= B) Try(k + 1);
    sum -= a[k];
    take[k] = false;
}

int main(int argc, char** argv) {
    preprocess(argc, argv);

    cin >> n >> A >> B;
    for (int i = 0; i < n; ++i) cin >> a[i];

    Try(0);
    cout << res;
}