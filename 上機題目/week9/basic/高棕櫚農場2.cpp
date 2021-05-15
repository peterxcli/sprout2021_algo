//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
#define MAXN 110
#define MAXM 1010
#define MAXK 110
int dp[MAXM][MAXK], v[MAXN], w[MAXN];
void solve_subtask() {
    memset(dp, 0, sizeof dp);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
    for (int i = 0; i < N; i++) {
        for (int k = M; k - w[i] >= 0; k--) {
            for (int j = 1; j <= K; j++) {
                dp[k][j] = max(dp[k-w[i]][j-1]+v[i], dp[k][j]);
            }
        }
    }
    cout << dp[M][K] << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}