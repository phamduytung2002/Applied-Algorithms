#include <bits/stdc++.h>
using namespace std;

string inp;
queue<string> s;

int main() {
    getline(cin, inp);
    while (inp != "#") {
        if (inp[1] == 'O') {
            if (s.size() > 0) {
                cout << s.front() << endl;
                s.pop();
            } else {
                cout << "NULL\n";
            }
        } else {
            string num = inp.substr(inp.find(' ') + 1);
            s.push(num);
        }
        getline(cin, inp);
    }
}