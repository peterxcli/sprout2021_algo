#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f
int n;
vector<int> g[MAXN];
int size[MAXN];
int ans, balance_size;
inline void init(){
	for(int i=0;i<n;++i)g[i].clear();
	balance_size=INF;
}
void dfs(int u,int pa){
	size[u]=1;
	int max_son_size=0;
	for(size_t i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v != pa){
			dfs(v, u);
			size[u] += size[v];
			max_son_size = max(max_son_size, size[v]);
		}
	}
	max_son_size = max(max_son_size, n-size[u]);
	if(max_son_size < balance_size || (max_son_size == balance_size && u < ans)){
		ans = u;
		balance_size=max_son_size;
	}
}
inline int tree_centroid(){
	dfs(0,-1);
	return ans;
}

void solve() {
    cin >> n;
    init();
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    cout << tree_centroid() << "\n";
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}