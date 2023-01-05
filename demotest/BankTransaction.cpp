#include <bits/stdc++.h>
using namespace std;

typedef int ll;

ll num_transaction = 0;
ll total_money = 0;

set<string> accs;
map<string, ll> money_from_acc;
map<string, vector<string>> edges;

bool cycle(string acc, int k) {
    map<string, int> dist;
    dist[acc] = 0;
    queue<string> q;
    q.push(acc);
    while (!q.empty() || dist[acc] < k) {
        string top = q.front();
        q.pop();
        for (string next : edges[top]) {
            dist[next] = dist[top] + 1;
            if (next == acc) {
                if (dist[acc] > k)
                    return false;
                else if (dist[acc] == k)
                    return true;
            }
            if (dist[next] >= k) {
                continue;
            }
            q.push(next);
        }
    }
    return dist[acc] == k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string tmp;
    cin >> tmp;
    while (tmp != "#") {
        string from_acc = tmp, to_acc, time, atm;
        ll money;
        cin >> to_acc >> money >> time >> atm;
        cout.flush();
        accs.insert(from_acc);
        accs.insert(to_acc);
        edges[from_acc].push_back(to_acc);

        money_from_acc[from_acc] += money;
        total_money += money;
        ++num_transaction;
        cin >> tmp;
    }

    string q;
    cin >> q;
    while (q != "#") {
        if (q == "?number_transactions") {
            cout << num_transaction << endl;
            cout.flush();
        } else if (q == "?total_money_transaction") {
            cout << total_money << endl;
            cout.flush();
        } else if (q == "?list_sorted_accounts") {
            for (auto acc : accs) {
                cout << acc << " ";
            }
            cout << endl;
            cout.flush();
        } else if (q == "?total_money_transaction_from") {
            string acc;
            cin >> acc;
            cout << money_from_acc[acc] << endl;
            cout.flush();
        } else {
            string acc;
            int k;
            cin >> acc >> k;
            cout << cycle(acc, k) << endl;
            cout.flush();
        }
        cin >> q;
    }
    return 0;
}