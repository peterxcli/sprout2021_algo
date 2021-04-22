#include<bits/stdc++.h>
using namespace std;
int GetVal(int a, int b) {
    return a+b;
}
void Report(int a) {
    cout << a << "\n";
}
int* a = new int [1000000];
void sol(int L,int R,int l,int r){// L,R index l,r bound
	if(L>R)return;
	int M = (L+R)/2;
	int ans = -1000000, ans_index = 0 ,tmp;
	for(int i=l;i<=r;i++){
		tmp = GetVal(M,i);
		if(tmp>ans){
			ans = tmp;
			ans_index = i;
		}
	}
	a[M] = ans_index;
	sol(L,M-1,l,ans_index);
	sol(M+1,R,ans_index+1,r);
}
void solve(int n,int m){
	sol(1,n,1,m);
	for(int i=1;i<=n;i++){
		Report(a[i]);
	}
}