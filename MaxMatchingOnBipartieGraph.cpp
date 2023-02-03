#include <bits/stdc++.h>
using namespace std;
/*
    There are  n tasks 1, ..., n and m staffs 1, ..., m. 
    T(i) is the set of staffs that can perform the task 
    i (i=1,...,n). Compute an assignment of staffs to tasks 
    such that each task is assigned to at most one staff and 
    each staff cannot be assigned to more than one task and 
    the number of tasks assigned is maximal.
*/
/*
    using Kuhn's alg, copied from 
    https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html#implementation
*/

int n, k, tmp1, tmp2;
// n: number of staff, k: number of task
vector<vector<int>> g(10001, vector<int>());
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> tmp1;
        for (int j = 0; j < tmp1; ++j) {
            cin >> tmp2;
            g[i].push_back(tmp2-1);
        }
    }

    mt.assign(k, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }
    int res = 0;
    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            ++res;
    cout << res;
}