#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans = 0;
int mat[9][9];
bool filled[9][9];

bool markrow[9][10];
bool markcol[9][10];
bool marksquare[3][3][10];

void Try(int row, int col) {
    if (col == 9) {
        if (row == 8) {
            ++ans;
            return;
        } else {
            Try(row + 1, 0);
            return;
        }
    } else if (filled[row][col]) {
        Try(row, col + 1);
        return;
    }
    for (int i = 1; i <= 9; ++i) {
        if (markrow[row][i] || markcol[col][i] || marksquare[row / 3][col / 3][i])
            continue;
        else {
            markrow[row][i] = true;
            markcol[col][i] = true;
            marksquare[row / 3][col / 3][i] = true;

            Try(row, col + 1);

            marksquare[row / 3][col / 3][i] = false;
            markcol[col][i] = false;
            markrow[row][i] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> mat[i][j];
            markrow[i][mat[i][j]] = true;
            markcol[j][mat[i][j]] = true;
            marksquare[i / 3][j / 3][mat[i][j]] = true;
            if (mat[i][j] == 0)
                filled[i][j] = false;
            else
                filled[i][j] = true;
        }
    }
    Try(0, 0);
    cout << ans;
}