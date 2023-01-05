#include<bits/stdc++.h>
using namespace std;

// not finished

const int maxn = 5001;
const int maxm = 10001;
int n, m;
vector<vector<int>> edges(maxn);
int c[maxn], d[maxn];


int main(){
    cin>>n>>m;
    for(int i=1; i<=n; ++i) cin>>c[i]>>d[i];
    for(int i=0; i<m; ++i){
        int v1, v2;
        cin>>v1>>v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
}