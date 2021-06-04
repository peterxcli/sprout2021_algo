#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
#define MAXN 1000005
vector<int> G[MAXN];
int depth[MAXN], low[MAXN], cut[MAXN];
bool vis[MAXN];

void targan(int v, int fa) {
    vis[v] = true;
    low[v] = depth[v] = (fa > 0 ? depth[fa] + 1 : 0);
    int son_cnt = 0;
    for (auto u : G[v]) {
        if (u == fa) continue;
        if (vis[u]) {
            low[v] = min(low[v], depth[u]);
        }
        else {
            son_cnt++;
            targan(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= depth[v]) cut[v] = true;
        }
    }
    if (fa == 0 && son_cnt == 1) cut[v] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    targan(1, 0);
    for (int i = 1; i <= N; i++) if (cut[i]) cout << i << "\n";
    return 0;
}