#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

const int N = 105, C = 100010;
int cost[N], weight[N];
int w[C + 1];

void solve_subtask() {
    int n, W;
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> weight[i] >> cost[i];
    memset(w, 0x7f, sizeof(w));
    w[0] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = C; j - cost[i] >= 0; --j)
            w[j] = min(w[j], w[j - cost[i]] + weight[i]);
    int c = C;
    while (w[c] > W)
        c--;
    cout << c << "\n";
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

// 定義狀態
// f(n,m)表示從前n個物品中選出價值總和恰為m的物品時，重量總合的最小值。若不存在一種取法使得價值為m，則f(n,m)=INF
// 狀態數：N*V (V為所有物品總合)

// 狀態轉移
// 如果最佳方案包含第n樣物品，則此最佳方案必為「選擇第n樣物品」及「從前n-1項物品中取出價值為m-vn的最佳方案」，因此可以得到 f(n,m) = f(n-1,m-vn)+wn
// 如果最佳方案不包含第n樣物品，則f(n,m) = f(n-1,m)
