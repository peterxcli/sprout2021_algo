//codeforces template
// #define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int k, vis[20];
vector<int> Lucky_set;

void print(vector<int> &x) {
    cout << x[0];
    for (int i = 1; i < x.size(); i++) cout << " " << x[i];
    cout << "\n";
}

void dfs(int cur, vector<int> x) {
    if (x.size() == 6) {
        print(x);
        return;
    }
    if (cur == k) return;
    x.push_back(Lucky_set[cur]);
    dfs(cur+1, x);
    x.pop_back();
    dfs(cur+1, x);
    
}

void solve_subtask() {
    Lucky_set.resize(k);
    for (int i = 0; i < k ;i++) cin >> Lucky_set[i];
    vector<int> QQ;
    dfs(0, QQ);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    while (cin >> k && k != 0) {
        if (cnt) cout << "\n";
        solve_subtask();
        cnt = 1;
    }
    return 0;
}