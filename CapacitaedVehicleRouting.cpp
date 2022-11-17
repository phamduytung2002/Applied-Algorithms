#include <bits/stdc++.h>
using namespace std;

// not done yet

// input
const int maxn = 15;
const int maxk = 6;
const int maxq = 55;
int n, k, q;
int d[maxn], c[maxn][maxn];

// objective
int min_total_distance = INT_MAX;

// constraints tracking
bool visited[maxn];
int current_trucks = 0;
int current_total_distance = 0;
int customer_list[maxn + maxk];
int capacity_list[maxn + maxk];
int num_visited_customer = 0;

// for pruning
int min_edge = INT_MAX;

bool check(int next_customer, int cus_num) {
    // minimal acceptance requirements
    if (visited[next_customer])
        return false;
    if (capacity_list[cus_num - 1] + d[next_customer] > q)
        return false;
    if (next_customer == 0 && current_trucks + 1 == k && num_visited_customer < n - 1)
        return false;
    // prune abundant branch
    if (current_total_distance + min_edge * (n - num_visited_customer + k - current_trucks) >= min_total_distance)
        return false;
    return true;
}

void add(int next_customer, int cus_num) {
    int current_customer = customer_list[cus_num - 1];
    if (next_customer == 0) {
        ++current_trucks;
        current_total_distance += c[current_customer][0];
    } else {
        visited[next_customer] = true;
        capacity_list[cus_num] = capacity_list[cus_num - 1] + d[next_customer];
        current_total_distance += c[current_customer][next_customer];
        customer_list[cus_num] = next_customer;
        ++num_visited_customer;
    }
}

void remove(int next_customer, int cus_num) {
    int current_customer = customer_list[cus_num - 1];
    if (next_customer == 0) {
        --current_trucks;
        current_total_distance -= c[current_customer][0];
    } else {
        --num_visited_customer;
        visited[next_customer] = false;
        capacity_list[cus_num] = 0;
        current_total_distance -= c[current_customer][next_customer];
        customer_list[cus_num] = 0;
    }
}

void record() {
    min_total_distance = min(current_total_distance, min_total_distance);
}

bool visited_all() {
    return num_visited_customer == n - 1;
}

void Try(int cus_num) {
    // Choose a customer to visit #cus_num
    if (customer_list[cus_num - 1] == 0) {
        for (int candidate_cus = 1; candidate_cus < n; ++candidate_cus) {
            if (!check(candidate_cus, cus_num)) continue;
            add(candidate_cus, cus_num);
            Try(cus_num + 1);
            remove(candidate_cus, cus_num);
        }
    } else {
        add(0, cus_num);
        if (visited_all() & check(0, cus_num))
            record();
        else
            Try(cus_num + 1);
        remove(0, cus_num);
        for (int candidate_cus = 1; candidate_cus < n; ++candidate_cus) {
            if (!check(candidate_cus, cus_num)) continue;
            add(candidate_cus, cus_num);
            Try(cus_num + 1);
            remove(candidate_cus, cus_num);
        }
    }
}

int main() {
    cin >> n >> k >> q;
    ++n;
    for (int i = 1; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
            min_edge = min(min_edge, c[i][j]);
        }
    }

    Try(1);
    cout << min_total_distance;
}