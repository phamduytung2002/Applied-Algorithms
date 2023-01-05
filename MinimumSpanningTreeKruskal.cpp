#include <bits/stdc++.h>
using namespace std;

/*
    Given a undirected connected graph G=(V,E) where V={1,…,N}.
    Each edge (u,v)∈E has weight w(u,v).
    Compute weight of minimum spanning tree of G.
*/

#define e pair<int, pair<int, int>>
#define w first
#define v1 second.first
#define v2 second.second

const int maxnm = 100001;
int n, m;
vector<e> edges(0);
int lab[maxnm];
// lab[i] < 0 -> root, lab[i] = - size of tree
// lab[i] > 0 -> lab[i] = parent of i
int res = 0;

int find_set(int v) {
    if (lab[v] < 0) {
        return v;
    } else {
        lab[v] = find_set(lab[v]);
        return lab[v];
    }
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (lab[a] > lab[b]) swap(a, b);
        lab[a] += lab[b];
        lab[b] = a;
    }
}

int main() {
    for (int i = 0; i < maxnm; ++i) lab[i] = -1;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int tmp1, tmp2, w;
        cin >> tmp1 >> tmp2 >> w;
        edges.push_back({w, {tmp1, tmp2}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < m; ++i) {
        e edge = edges[i];
        if (find_set(edge.v1) == find_set(edge.v2))
            continue;
        else {
            res += edge.w;
            union_set(edge.v1, edge.v2);
        }
    }
    cout << res;
}