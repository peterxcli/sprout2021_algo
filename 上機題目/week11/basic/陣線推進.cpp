#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n, m;
int in[N];
int path[N];
int sum = 0;
vector<int> G[N];
void Topsort() {
    priority_queue<int, vector<int>, greater<int>> Q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            Q.push(i);

    while (!Q.empty()) {
        int x = Q.top();
        Q.pop();
        sum++;
        path[++cnt] = x;
        for (int i = 0; i < G[x].size(); i++) {
            int y = G[x][i];
            in[y]--;

            if (in[y] == 0)
                Q.push(y);
        }
    }
}
int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(in, 0, sizeof(in));
        sum = 0;
        for (int i = 0; i < n; i++)
            G[i].clear();
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            in[y]++;
        }
        Topsort();
        if (sum != n) {
            cout << "QAQ\n";
            continue;
        }
        for (int i = 1; i <= n; i++)
            cout << path[i] << (i!=n?" ":"\n");
    }
    return 0;
}