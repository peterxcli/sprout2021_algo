#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long

const int mod = 10000019;

vector<int> a;

int counting (int l, int r) {
    if (l == r) return 0;
    int m = (l+r) >> 1;
    int ret = (counting(l, m) + counting(m+1, r)) % mod;
    int idx = m+1, prefix = 0;
    for (int i = l; i <= m; i++) {
        while (idx <= r && a[i] > a[idx]) {
            prefix += a[idx];
            idx++;
        }
        ret = (ret + prefix + a[i]*(idx-m-1))%mod;
    }
    int pointer_lhs = l, pointer_rhs = m+1;
    vector<int> tmp(r-l+1);
    for (int i = 0; i < r-l+1; i++) {
        if (pointer_lhs == m+1) {
            tmp[i] = a[pointer_rhs];
            pointer_rhs++;
        }
        else if (pointer_rhs == r+1) {
            tmp[i] = a[pointer_lhs];
            pointer_lhs++;
        }
        else {
            if (a[pointer_lhs] < a[pointer_rhs]) {
                tmp[i] = a[pointer_lhs];
                pointer_lhs++;
            }
            else {
                tmp[i] = a[pointer_rhs];
                pointer_rhs++;
            }
        }
    }
    for (int i = 0; i < r-l+1; i++) a[l+i] = tmp[i];
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    cout << counting(0, N-1) << "\n";
    // for (auto x:a) cout << x << " ";
    return 0;
}