#include <bits/stdc++.h>

using namespace std;

int f[100010], size[100010];

struct box{
    int f, size;
};

vector<box> dis;

void dfs(int x, int &src) {
    if (dis[x].f == x) return;
    dis[dis[x].f].size += dis[src].size;
    dfs(dis[x].f, src);
}

void solve() {
    int n, m;
    cin >> n >> m;
    dis.resize(n+1);
    for (int i = 1; i <= n; i++) {
        dis[i].f = i;
        dis[i].size = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dis[y].f = x;
        dfs(y, y);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int idx;
        cin >> idx;
        cout << dis[idx].size << "\n";
    }
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}