#include <bits/stdc++.h>
using namespace std;

int m, n;
bool can_teach[11][31];  // [teacher][course], teacher [0] can teach course [1]
bool conflict[31][31];   // [course][course], 2 course [0] and [1] are conflict

bool is_teaching[11][31];  // [teacher][course], teacher [0] is teaching course [1]
int load[11];              // load for each teacher

int minimaxload = INT_MAX;  // objective

bool check(int candidate_teacher, int course_id) {
    // check if course_id can be assigned to candidate_teacher
    if (!can_teach[candidate_teacher][course_id])
        return false;
    for (int i = 0; i < n; ++i) {
        if (is_teaching[candidate_teacher][i] && conflict[i][course_id]) {
            return false;
        }
    }
    // prune
    if (load[candidate_teacher] + 1 >= minimaxload)
        return false;
    return true;
}

void add(int teacher, int course_id) {
    is_teaching[teacher][course_id] = true;
    ++load[teacher];
}

void remove(int teacher, int course_id) {
    is_teaching[teacher][course_id] = false;
    --load[teacher];
}

void ghinhan() {
    int cur_max_load = 0;
    for (int i = 0; i < n; ++i) {
        cur_max_load = max(cur_max_load, load[i]);
    }
    minimaxload = min(cur_max_load, minimaxload);
}

void Try(int k) {
    // assign teacher to course k
    for (int i = 0; i < m; ++i) {
        if (!check(i, k)) continue;
        add(i, k);
        if (k == n - 1) {
            ghinhan();
        } else {
            Try(k + 1);
        }
        remove(i, k);
    }
}

int main() {
    memset(can_teach, 0, sizeof(can_teach));
    memset(load, 0, sizeof(load));
    memset(conflict, 0, sizeof(conflict));
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int tmp;
            cin >> tmp;
            can_teach[i][tmp - 1] = true;
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        conflict[tmp1 - 1][tmp2 - 1] = true;
        conflict[tmp2 - 1][tmp1 - 1] = true;
    }

    Try(0);

    cout << minimaxload;
}