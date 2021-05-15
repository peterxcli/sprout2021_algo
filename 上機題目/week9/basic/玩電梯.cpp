//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
#define MAXN 2021
#define MAXK 2021
const int mod = 1000000007;
int dp[MAXN][MAXK];
void solve_subtask() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    // for (int i = a; i < )
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
// dp[i] = dp[i-1]+dp[i-2]+...+dp[2]+dp[1]