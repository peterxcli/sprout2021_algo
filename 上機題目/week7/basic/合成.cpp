//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

void solve_subtask() {
    int N;
    cin >> N;
    vector<vector<int> > dp(N+1, vector<int>(N+1, 1e9));
    vector<int> a(N+1), sum(N+1);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) sum[i] = sum[i-1]+a[i];
    for (int i = 0; i <= N; i++) dp[i][i] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j+i <= N; j++) {
            for (int k = j; k < j+i; k++) {
                dp[j][i+j] = min(dp[j][i+j], dp[j][k]+dp[k+1][i+j]-sum[j-1]+sum[i+j]);
            }
        }
    }
    cout << dp[1][N] << "\n";
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