#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
#define int long long 
int dp[MAXN];
const int M = 1000007;
int32_t main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
	dp[0] = 1, dp[1] = 0, dp[2] = 3;
	int t, n;
	cin >> t;
	for(int i = 4; i < MAXN; i += 2){
		dp[i]=(4*dp[i-2]-dp[i-4]+M)%M;
	}
	while(t--){
		cin >> n;
		if(n&1) cout << 0 << "\n";
		else cout<< dp[n] << "\n";
	}
}