//https://codeforces.com/contest/449/problem/C
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
#define MAXN 100010

bool iscomp[MAXN], vis[MAXN];
 
void prime_table(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (iscomp[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            iscomp[j] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    prime_table(n);
    vector<int> g;
    vector<pair<int, int> > ans;
    for (int i = n / 2; i > 1; i--) {
        if (iscomp[i])
            continue;
        g.clear();
 
        for (int j = i; j <= n; j += i) {
            if (vis[j] == 0)
                g.push_back(j);
        }
        if (g.size() & 1)
            swap(g[1], g[g.size()-1]);
        for (int i = 0; i < g.size() - 1; i += 2) {
            ans.push_back(make_pair(g[i], g[i+1]));
            vis[g[i]] = vis[g[i+1]] = 1;
        }
    }
 
    cout << ans.size() << "\n";
    for (auto x:ans) cout << x.first << " " << x.second << "\n"; 
    return 0;
}