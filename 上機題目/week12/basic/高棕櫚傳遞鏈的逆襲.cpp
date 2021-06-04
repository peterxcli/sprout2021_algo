#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
vector<int> G[MAXN];
vector<int> edge[MAXN];
int depth[MAXN], low[MAXN], edge_sum[MAXN];
bool vis[MAXN], bridge[MAXN];
pair<int, int> edge_info[MAXN];

void targan(int v, int fa) {
    vis[v] = true;
    low[v] = depth[v] = (fa > 0 ? depth[fa] + 1 : 0);
    int son_cnt = 0;
    for (auto idx : edge[v]) {
        int u = edge_sum[idx] - v;
        if (u == fa) continue;
        if (vis[u]) {
            low[v] = min(low[v], depth[u]);
        }
        else {
            son_cnt++;
            targan(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > depth[v]) bridge[idx] = true;
        }
    }
    // if (fa == 0 && son_cnt == 1) bridge[v] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].emplace_back(i);
        edge[y].emplace_back(i);
        edge_sum[i] = x + y;
        edge_info[i].first = x, edge_info[i].second = y;
    }
    targan(1, 0);
    for (int i = 0; i < M; i++) if (bridge[i]) cout << edge_info[i].first << " " << edge_info[i].second << "\n";
    return 0;
}

// 先把邊編號
// 然後開vector<int> edges[點數]
// 然後要存邊時把編號push進去
// 然後再開int[邊編號]=點1編號+點2編號
// 要找結束的點=int[邊編號]-起始點編號