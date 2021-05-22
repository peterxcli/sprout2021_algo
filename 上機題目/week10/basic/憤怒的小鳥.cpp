#include <bits/stdc++.h>
#define eps 1e-6
#define MANY_SUBTASK
#pragma GCC optimize(2, "Ofast", "inline")
#define endl '\n'
using namespace std;
double x[24], y[24];
int f[16777216], g[24][24];
void solve_subtask() {
    memset(g, 0, sizeof(g));
    int n, m, i, j, k;
    double a, b;
    cin >> n;
    for (i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                a = (x[j] * y[i] - x[i] * y[j]) / (x[i] * x[j] * (x[i] - x[j]));
                b = (x[j] * x[j] * y[i] - x[i] * x[i] * y[j]) / (x[i] * x[j] * (x[j] - x[i]));
                if (a <= -eps)
                    for (k = 0; k < n; k++)
                        if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) <= eps)
                            g[i][j] |= 1 << k;
            }
        }
    }
    f[0] = 0;
    for (i = 1; i < (1 << n); i++) {
        for (j = 0; j < n; j++)
            if ((1 << j) & i)
                break;
        f[i] = f[i ^ (1 << j)] + 1;
        for (k = 0; k < n; k++)
            if (k != j && (1 << k) & i)
                f[i] = min(f[i], f[i ^ (i & g[j][k])] + 1);
    }
    cout << f[(1 << n) - 1] << "\n";
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