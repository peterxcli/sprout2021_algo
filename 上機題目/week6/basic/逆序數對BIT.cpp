//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define lowbit(x) x&-x
using namespace std;
int t = 1, n;
struct BIT {
    vector<int> v;
    void modify(int pos, int val) {
        for (; pos < v.size(); pos += lowbit(pos))
            v[pos] += val;
    }  
    int query(int pos) {
        int ret = 0;
        for (; pos; pos -= lowbit(pos))
            ret += v[pos];
        return ret;
    }
};
void solve_subtask() {
    cout << "Case #" << t++ << ": ";
    int ;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n && n) {
        solve_subtask();
    }
    return 0;
}