//https://codeforces.com/problemset/problem/242/D
// #define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define MAXN 100010
using namespace std;

vector<int> g[MAXN], a, record;
int vis[MAXN], n, m, val[MAXN], ans;

void check(int x) {
    record.emplace_back(x+1);
    ans++;
    vis[x] = true;
    val[x]++;
    for (auto v:g[x]) val[v]++;
    for (auto v:g[x]) {
        if (val[v] == a[v] && !vis[v]) {
            check(v);
        }
    }
}

void solve_subtask() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x-1].emplace_back(y-1);
        g[y-1].emplace_back(x-1);
    }
    for (int i = 0; i < n; i++) cin >> a[i];
    int keep = 1;
    while (keep) {
        keep = 0;
        // for (int i = 0; i < n; i++) cout << val[i] << " ";cout << "\n";////////////////////////////////////
        for (int i = 0; i < n; i++) {
            if (val[i] == a[i] && !vis[i]) {
                keep = 1;
                check(i);
            }
        }
    }
    bool flag = 1;
    for (int i = 0; i < n; i++) 
        if (val[i] == a[i]) flag = 0; 
    if (flag) {
        cout << ans << "\n";
        if (ans > 0) {
            cout << record[0];
            for (int i = 1; i < record.size(); i++) cout << " " << record[i];
            cout << "\n";
        }
    }
    else cout << "-1\n";

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}