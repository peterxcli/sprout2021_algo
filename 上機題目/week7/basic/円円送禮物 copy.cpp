//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define MAXN 100010
using namespace std;
const int mod = 1000007;
int dp[MAXN][3][2];//0:red, 1:green, 2:blue, 第三高維代表右端的顏色
void build() {
    dp[1][0][0] = dp[1][1][1];
    
}
void solve_subtask() {
    memset(dp, 0, sizeof dp);
    int N, ans = 0;
    cin >> N;
    
    memset(dp, 0, sizeof dp);
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