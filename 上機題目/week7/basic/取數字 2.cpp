//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int N, K, ans= 0;
    cin >> N >> K;
    vector<int> dp(N), a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    dp[0] = a[0];dp[1] = a[1];
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j <= i-K; j++) {
            // if (i-j < 0) break;
            tmp = max(tmp, dp[j]);
        }
        dp[i] = tmp+a[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n"; 
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