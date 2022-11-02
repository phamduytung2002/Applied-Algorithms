#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

void print(){
    for(int i=0; i<n; ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cin>>n;
    for(int i=0; i<n; ++i){
        a[i] = i+1;
    }
    do{
        print();
    }
    while(next_permutation(a, a+n));
}