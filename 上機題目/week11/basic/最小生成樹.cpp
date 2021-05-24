#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define MAXN 200010
int f[MAXN], size[MAXN];

struct disjoint_set{
    void init() {
        for (int i = 0; i < MAXN; i++) f[i] = i, size[i] = 1;
    }
    bool is_same(int u, int v) {
        return (findf(u) == findf(v));
    }
    void Union(int u, int v){
        u = findf(u), v = findf(v);
        if (size[u] > size[v]) swap(u, v);
        size[u] += size[v], size[v] = 0;
        f[v] = u;
    }
    int findf(int x) {
        if (x == f[x]) return x;
        return f[x] = findf(f[x]);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    disjoint_set dis;
    dis.init();
    cin >> N >> M;
    vector<pair<int, pair<int, int>> > edges(M);
    for (int i = 0; i < M; i++) cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto edge:edges) {
        if (dis.is_same(edge.second.first, edge.second.second)) continue;
        ans += edge.first;
        dis.Union(edge.second.first, edge.second.second);
    }
    cout << ans << "\n";
    return 0;
}