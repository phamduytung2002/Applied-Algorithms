#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

void debug(function<void()> t) {
#ifdef DEBUG
    cout << "\n*****DEBUG*****\n";
    t();
    cout << "\n************endDEBUG************\n";
#endif
}

int n, k, x[100];
bool choosen[100];

void Try(int t) {
    if (t == k) {
        for (int i = 1; i <= n; ++i) {
            if (choosen[i]) cout << i << " ";
        }
        cout << endl;
    }
    for (int i = x[t - 1]; i <= n; ++i) {
        if (i == 0) continue;
        if (choosen[i]) continue;
        x[t] = i;
        choosen[i] = true;
        Try(t + 1);
        choosen[i] = false;
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef OFFLINE
    const string test_name = argv[1];
    freopen((test_name).c_str(), "r", stdin);
    freopen((test_name + ".out").c_str(), "w", stdout);
#endif

    cin >> k >> n;
    Try(0);
    return 0;
}