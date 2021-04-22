#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005
int ans[MAXN][3], G[MAXN][3], B[MAXN][3];
const int M = 1000007;

void init() {
    for (int i = 0; i < 3; i++) 
        ans[0][i] = 1;
    G[0][1] = 1;
    B[0][2] = 1;
    for (int i = 1; i < MAXN; i++) {
        G[i][0] = (G[i-1][0] + G[i-1][1] + G[i-1][2])%M;
        G[i][1] = (G[i-1][0] + G[i-1][1])%M;
        G[i][2] = (G[i-1][0] + G[i-1][2])%M;
    }
    for (int i = 1; i < MAXN; i++) {
        B[i][0] = (B[i-1][0] + B[i-1][1] + B[i-1][2])%M;
        B[i][1] = (B[i-1][0] + B[i-1][1])%M;
        B[i][2] = (B[i-1][0] + B[i-1][2])%M;
    }
    for (int i = 1; i < MAXN; i++) {
        ans[i][0] = (ans[i-1][0] + ans[i-1][1] + ans[i-1][2])%M;
        ans[i][1] = (ans[i-1][0] + ans[i-1][1])%M;
        ans[i][2] = (ans[i-1][0] + ans[i-1][2])%M;
    }
}
int32_t main(void) {
    int T, N;
    init();
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << (ans[N-1][0]+ans[N-1][1]+ans[N-1][2]-G[N-1][2]-B[N-1][1]+2*M)%M << "\n";
    }
}