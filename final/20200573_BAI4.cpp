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

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef OFFLINE
    const string test_name = argv[1];
    freopen((test_name).c_str(), "r", stdin);
    freopen((test_name + ".out").c_str(), "w", stdout);
#endif



    return 0;
}