//codeforces template
// #define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int N;
struct Data{
    int c, e;
    bool operator<(Data rhs) {
        return e > rhs.e;
    }
};

void solve_subtask() {
    vector<int> C(N), E(N);
    int prefix = 0;
    vector<Data> data(N);
    for (int i = 0; i < N; i++) cin >> data[i].c >> data[i].e;
    sort(data.begin(), data.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        prefix += data[i].c;
        ans = max(prefix+data[i].e, ans);
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
    while (cin >> N && N != 0)
    {
        solve_subtask();
    }
    return 0;
}