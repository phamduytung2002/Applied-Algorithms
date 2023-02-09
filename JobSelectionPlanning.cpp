#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

/*
    Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i)
    and associated profit p(i) if the job is finished before the
    deadline. Every job takes the single unit of time, so the
    minimum possible deadline for any job is 1. It is also noted
    that no more than one job can be executed at a time.
    Select and schedule a subset of jobs of J such that the total
    profits is maximal.
*/

typedef pair<int, int> pii;
#define d second
#define p first
const int maxn = 10001;
int n, res = 0;
pii dat[maxn];
set<int> untakendate;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < maxn; ++i) {
        untakendate.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> dat[i].d >> dat[i].p;
    }
    sort(dat, dat + n, greater<pii>());
    for (int i = 0; i < n; ++i) {
        auto u = untakendate.upper_bound(dat[i].d);
        // careful:
        // set.upper_bound(...) : O(log n)
        // upper_bound(set.begin(), set.end(), ...) : O(n)
        --u;
        if (*u != 0) {
            untakendate.erase(u);
            res += dat[i].p;
        }
    }
    cout << res;
}
