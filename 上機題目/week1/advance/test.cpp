#include <bits/stdc++.h>

using namespace std;

int ary[1000000],stk[1000000],snu[1000000],sn;
long long ans;
int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
	int T,n,i;
	cin >> T;
	while (T--) {
		cin >> n;
		for (i=0;i<n;i++)cin >> ary[i];
		ans = sn = 0;
		for (i=0;i<n;i++) {
			//pop and count
			while (sn>0 && stk[sn-1]<ary[i]) {
				--sn;
				//top->ary[i]
				ans++;
				//(top-1)<-top
				if (sn>0)ans++;
				//tops<-->tops , ex: 2 2 2 [2],should+3
				ans+=snu[sn]-1;
				//same element case
				if (snu[sn]>1)
					snu[sn++]--;
			}
			
			//push
			if (sn>0 && stk[sn-1] == ary[i])
				snu[sn-1]++;
			else {
				stk[sn++]=ary[i];
				snu[sn-1]=1;
			}
		}
		while (sn>0) {
			--sn;
			//(top-1)<-top
			if (sn>0)ans++;
			//tops<-->tops , ex: 2 2 2 [2],should+3
			ans+=snu[sn]-1;
			//same element case
			if (snu[sn]>1)
				snu[sn++]--;
		}
		cout << ans << "\n";
	}
}