#include <bits/stdc++.h>
using namespace std;

int n;
bool a[21];

void print() {
    for (int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;
}

bool chk() {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 1 && a[i + 1] == 1) return false;
    }
    return true;
}

int main() {
    cin >> n;
    while (true) {
        if (chk()) print();
        for (int dig = n - 1; dig >= 0; dig--) {
            if (a[dig] == 0) {
                a[dig] = 1;
                break;
            } else {
                a[dig] = 0;
            }
            if (dig == 0) return 0;
        }
    }
}