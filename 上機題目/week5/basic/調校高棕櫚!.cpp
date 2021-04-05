//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int cnt[10];

void solve_subtask() {
    // vector<int> ans;
    fill(cnt, cnt+10, 0);
    int N;
    cin >> N;
    if (N == 1) {cout << "1\n";return;}
    for (int i = 9; i != 1; i--) {
        while (N % i == 0) {
            cnt[i]++;
            N /= i; 
        }
    }
    if (N != 1) {cout << "-1\n";return;}
    string ans;
    for (int i = 2; i < 10; i++) {
        while (cnt[i] != 0) {
            ans += char(i+'0');
            cnt[i]--;
        }
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
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}