#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<char> pa;
    string s;
    cin >> s;
    bool answer = true;
    if (s.size() % 2 == 1)
        answer = false;
    else
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                pa.push(s[i]);
            } else {
                if (pa.empty()) {
                    answer = false;
                    break;
                } else if (s[i] != pa.top() + 1 && s[i] - pa.top() != 2) {
                    answer = false;
                    break;
                } else
                    pa.pop();
            }
        }
    cout << answer;
}