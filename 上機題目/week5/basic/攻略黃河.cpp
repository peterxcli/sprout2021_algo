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
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int tmp = 1, ans = 1, cur = a[0];
    for (int i = 1; i < N; i++) {
        if (tmp && cur > a[i]) {ans++;tmp = !tmp;}
        if (!tmp && cur < a[i]) {ans++;tmp = !tmp;}
        cur = a[i];
    }
    if (!tmp) ans--;
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