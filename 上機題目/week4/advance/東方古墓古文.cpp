#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define N 100000
int a[N];
bool sol(int k,int n,int m){
	int tmp = 0 ,cnt = m;
	for(int i=0;i<n&&cnt>0;i++){
		if(a[i]>k)return false;
		if(tmp+a[i] > k){
			tmp = a[i];
			cnt--;
		}else{
			tmp+=a[i];
		}
	}
	if(cnt <= 0) return false;
	else return true;
}
main(){
	ios::sync_with_stdio(false);
	//cin.tie(0);
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++)cin>>a[i];
		int L = 1 , R = INF ;
		int M;
		while(L<R){
			M= (R-L)/2 + L;
			if(sol(M,n,m))R=M;
			else L=M+1;
		}
		cout<<L<<"\n";
	}
}