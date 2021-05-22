#include <bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
int D[N], DP[N], n, k;
struct MP {
    int a, b, i;
    MP() {}
    MP(int _a, int _b, int _i) : a(_a), b(_b), i(_i) {}
};
bool tt(MP t1, MP t2, MP t3) {
    return min(t1.i + k, (t2.b - t1.b) / (t1.a - t2.a)) > (t3.b - t2.b) / (t2.a - t3.a);
}
bool check(MP t1, MP t2, int x) {
    return t1.a * x + t1.b <= t2.a * x + t2.b;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = n; i > 0; i--)
        cin >> D[i];
    for (int i = 0; i < n; i++) D[i + 1] += D[i];
    deque<MP> qq;
    qq.push_back(MP(0, 0, 0));
    for (int i = 1; i <= n; i++) {
        if (!qq.empty() && qq.front().i < i - k)
            qq.pop_front();
        while (qq.size() >= 2 && check(qq[0], qq[1], i))
            qq.pop_front();
        int a = qq.front().a, b = qq.front().b;
        DP[i] = a * i + b - i * i;
        a = 2 * i, b = DP[i] + D[i] - i * i;
        while (qq.size() >= 2 && tt(qq[qq.size() - 2], qq[qq.size() - 1], MP(a, b, i))) {
            qq.pop_back();
        }
        qq.push_back(MP(a, b, i));
    }
    cout << DP[n] << endl;
    cin >> n;
}