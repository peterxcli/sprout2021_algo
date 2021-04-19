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
    vector<int> dp(N), a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    dp[0] = a[0];dp[1] = a[1];dp[2] = max(a[0]+a[2], a[2]);
    for (int i = 3; i < N; i++) dp[i] = max(max(dp[i-2], dp[i-3]), dp[i])+a[i];
    cout << max(dp[N-1], dp[N-2]) << "\n"; 
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