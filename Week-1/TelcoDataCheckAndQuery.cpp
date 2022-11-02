#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool no_wrong_number = true;
map<string, ll> num_calls_from;
map<string, ll> num_time_calls_from;
ll num_total_calls;

void check(string num) {
    if (num.size() != 10) {
        no_wrong_number = false;
    } else {
        for (int i = 0; i < 10; ++i) {
            if (num[i] < '0' || num[i] > '9') {
                no_wrong_number = false;
            }
        }
    }
}

ll total_time(string from_time, string to_time) {
    ll from_h, from_m, from_s, to_h, to_m, to_s;
    from_h = (from_time[0] - '0') * 10 + (from_time[1] - '0');
    from_m = (from_time[3] - '0') * 10 + (from_time[4] - '0');
    from_s = (from_time[6] - '0') * 10 + (from_time[7] - '0');
    to_h = (to_time[0] - '0') * 10 + (to_time[1] - '0');
    to_m = (to_time[3] - '0') * 10 + (to_time[4] - '0');
    to_s = (to_time[6] - '0') * 10 + (to_time[7] - '0');
    return (to_h - from_h) * 3600 + (to_m - from_m) * 60 + (to_s - from_s);
}

int main() {
    string inp;
    cin >> inp;
    while (inp != "#") {
        string from_num, to_num, date, from_time, to_time;
        cin >> from_num >> to_num >> date >> from_time >> to_time;
        if (no_wrong_number) {
            check(from_num);
            check(to_num);
        }
        num_calls_from[from_num] += 1;
        num_time_calls_from[from_num] += total_time(from_time, to_time);
        ++num_total_calls;
        cin >> inp;
    }
    cin >> inp;
    while (inp != "#") {
        if (inp == "?check_phone_number") {
            cout << int(no_wrong_number) << endl;
        } else if (inp == "?number_calls_from") {
            string num;
            cin >> num;
            cout << num_calls_from[num] << endl;
        } else if (inp == "?number_total_calls") {
            cout << num_total_calls << endl;
        } else if (inp == "?count_time_calls_from") {
            string num;
            cin >> num;
            cout << num_time_calls_from[num] << endl;
        }
        cin >> inp;
    }
}