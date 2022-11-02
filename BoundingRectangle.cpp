#include <bits/stdc++.h>
using namespace std;

int n;
int xmin(INT_MAX), xmax(INT_MIN), ymin(INT_MAX), ymax(INT_MIN);

int main() {
    cin >> n;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        xmin = min(xmin, min(a, c));
        xmax = max(xmax, max(a, c));
        ymin = min(ymin, min(b, d));
        ymax = max(ymax, max(b, d));
    }
    cout << (xmax - xmin) * (ymax - ymin);
}