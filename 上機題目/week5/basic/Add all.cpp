#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int N;

void solve () {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; i++) {
        int tmp;cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while(pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += a+b;
        pq.push(a+b);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N && N != 0) solve();
}