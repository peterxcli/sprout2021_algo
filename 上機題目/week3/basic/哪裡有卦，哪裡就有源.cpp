#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, m, flag, vis[MAXN], gender[MAXN];

vector<int> g[MAXN];

void dfs(int x, int fa) {
    vis[x] = true;
    if (fa != -1) {
        if (gender[x] == 0) {
            gender[x] = gender[fa]*(-1);
        }
        else if (gender[x] == gender[fa]) {
            flag = 1;
            return;
        }
    }
    for (auto u:g[x]) {
        if (gender[u] == 0) {
            gender[u] = gender[x]*(-1);
        }
        else if (gender[u] == gender[x]) {
            flag = 1;
            return;
        }
        if (vis[u]) continue;
        dfs(u, x);
        
    }
}

void init() {
    for (int i = 0; i < n; i++) g[i].clear();
    flag = 0;
    memset(vis, 0, sizeof(vis));
    memset(gender, 0, sizeof(gender));
}

void solve() {
    cin >> m;
    init();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (gender[i] == 0) gender[i] = 1;
        dfs(i, -1);
    }
    if (flag) cout << "RAINBOW.\n";
    else cout << "NORMAL.\n";
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    while (cin >> n && n != 0) {
        solve();
    }
}