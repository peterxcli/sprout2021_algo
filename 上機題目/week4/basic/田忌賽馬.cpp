//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int N, K;
vector<pair<int, int>> horses;
vector<int> enemy;

bool check(int m) {
    vector<int> tmp(N);
    for (int i = 0; i < N; i++) {
        tmp[i] = horses[i].first+horses[i].second*m;
    }
    sort(tmp.begin(), tmp.end());
    // reverse(tmp.begin(), tmp.end());
    int win = 0, idx = 0;
    for (int i = 0; i < N; i++) {
        while(idx < N && enemy[i] >= tmp[idx]) idx++;
        if (idx == N) break;
        win++;
        idx++;
    }
    if (win >= K) return true;
    else return false;
}

void solve_subtask() {
    
    cin >> N >> K;
    horses.resize(N); enemy.resize(N);
    for (int i = 0; i < N; i++) cin >> horses[i].first >> horses[i].second;
    for (int i = 0; i < N; i++) cin >> enemy[i];
    sort(enemy.begin(), enemy.end());
    // reverse(enemy.begin(), enemy.end());
    int l = 0, r = 100000000;
    if (!check(r)) {cout << "-1\n";return;}
    while(l < r) {
        int m = l+r >> 1;
        if (check(m)) r = m;
        else l = m+1;
    } 
    cout << l << "\n";
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