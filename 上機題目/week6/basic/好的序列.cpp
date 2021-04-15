#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;

void solve(int l ,int r) {
    if (r <= l+1) return;
    int m = l+r >> 1;
    vector<int> lhs(m-l+1), rhs(r-m);
    for (int i = 0, j = l; i < m-l+1 && j <= r;) {
        if (a[j++] & 1) lhs[i++] = a[j-1];
    }
    for (int i = 0, j = l; i < r-m && j <= r;) {
        if (!(a[j++] & 1)) rhs[i++] = a[j-1];
    }
    for (int i = 0, j = l; i < m-l+1; i++, j++) {
        lhs[i] = (lhs[i]+1)/2;
        a[j] = lhs[i];
        // cout << lhs[i] << " ";
    }
    for (int i = 0, j = m+1; i < r-m; i++, j++) {
        rhs[i] /= 2;
        a[j] = rhs[i];
        // cout << rhs[i] << " ";
    }
    solve(l, m);solve(m+1, r);
    for (int i = l; i <= m; i++) a[i] = a[i]*2 - 1;
    for (int i = m+1; i <= r; i++) a[i] = a[i]*2;
}

int32_t main() {
    int N; 
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) a[i] = i+1;
    solve(0, N-1);
    cout << a[0];
    for (int i = 1; i < N; i++) cout << " " << a[i];
    cout << "\n";
}