#include <bits/stdc++.h>
using namespace std;

int n;
int dis[20][20];
int sol[20];
int ans = INT_MAX;

bool ucv(int k, int i) {
    for (int j = 1; j < k; ++j) {
        if (sol[j] == i) return false;
    }
    return true;
}

void Try(int k, int tmpans) {
    for (int i = 1; i < n; ++i) {
        if (ucv(k, i)) {
            sol[k] = i;
            tmpans += dis[sol[k - 1]][sol[k]];
            if (tmpans < ans) {
                if (k == n - 1) {
                    tmpans += dis[sol[k]][sol[0]];
                    if (tmpans < ans) ans = tmpans;
                    tmpans -= dis[sol[k]][sol[0]];
                } else
                    Try(k + 1, tmpans);
            }
            tmpans -= dis[sol[k - 1]][sol[k]];
            sol[k] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dis[i][j];
        }
    }

    Try(1, 0);

    cout << ans << endl;
}