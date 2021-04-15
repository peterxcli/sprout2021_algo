//https://codeforces.com/problemset/problem/351/E

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
#define N 1000010
 
int a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		a[i] = abs(a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int cnt1 = 0, cnt2 = 0;
		for(int j = 1; j < i; j++)
			cnt1 += (a[j]<a[i]);
		for(int j = i+1; j <= n; j++)
			cnt2 += (a[j]<a[i]);
		ans += min(cnt1, cnt2);
	}
	cout << ans << "\n";
}