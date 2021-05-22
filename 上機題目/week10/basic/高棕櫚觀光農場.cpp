#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f;
const int MAX_N = 16;
int n;
int dis[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int32_t main() {
    int T;
    cin >> T;
    while (T--) { 
        memset(dp, INF, sizeof(dp));
        cin >> n;
        int Smax = (1<<n)-1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j <= n - i - 1; j++) {
                int x;
                cin >> x;
                dis[i][i + j] = dis[i + j][i] = x;
            }
        }
        dp[Smax][0] = 0;
        for (int S = Smax; S >= 0; S--) {
            for (int v = 0; v < n; v++) {
                for (int u = 0; u < n; u++) {
                    if (!(S >> u & 1) && v != u) {
                        dp[S][v] = min(dp[S][v], dp[S | 1<<u][u] + dis[v][u]);
                    }
                }
            }
        }
        cout << dp[0][0] << "\n";
    }
}