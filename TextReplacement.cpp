#include <bits/stdc++.h>
using namespace std;

// not finished

string T, P1, P2;

int main() {
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);
    int pos = T.find(P1);
    while (pos != string::npos) {
        T.replace(pos, pos + P1.size(), P2);
        pos = T.find(P1, pos + P2.size());
        cout<<T<<endl;
    }
    cout << T;
}