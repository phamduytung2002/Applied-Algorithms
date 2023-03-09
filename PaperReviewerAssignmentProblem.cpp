#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

/*
    The chair of a conference must assign scientific
    papers to reviewers in a balance way. There are N
    papers 1, 2, …, N and M reviewers 1, 2, …, M. Each
    paper i has a list L(i) of reviewers who are willing
    to review that paper. A review plan is an assignment
    reviewers to papers. The load of a reviewer is the number
    of papers he/she have to review. Given a constant b,
    compute the assignment such that
    Each paper is reviewed by exactly b reviewers.
    The maximum load of all reviewers is minimal 
        Input
    Line 1 contains N, M and b
    Line i+1 (i = 1,…,N) contains a positive integer k
    followed by k positive integers representing the list L(i)
        Output
    Unique line contains the maximum load for all reviewers of the
    solution found or contains -1 if no solution found
*/

void debug(function<void()> t) {
#ifdef DEBUG
    cout << "\n*****DEBUG*****\n";
    t();
    cout << "\n************endDEBUG************\n";
#endif
}

double n, m, b, k, tmp;
vector<int> l[20];

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef OFFLINE
    const string test_name = argv[1];
    freopen((test_name).c_str(), "r", stdin);
    freopen((test_name + ".out").c_str(), "w", stdout);
#endif
    cin >> n >> m >> b;

    for (int i = 0; i < m; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> tmp;
            l[i].push_back(tmp);
        }
    }

    bool noans = false;
    for (int i = 1; i <= m; ++i) {
        if (l[i].size() < b) {
            noans = true;
            break;
        }
    }
    if (noans)
        cout << -1;
    else
        cout << ceil(n * b / m); // test cases are not strong enough

    return 0;
}