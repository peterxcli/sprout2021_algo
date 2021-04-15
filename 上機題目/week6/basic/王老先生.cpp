#include<bits/stdc++.h>
using namespace std;
void Report(int x1, int y1, int x2, int y2, int x3, int y3) {
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";
}
void sol(int n, int x, int y, int a, int b){
	const int dx[4] = {0, 0, 1, 1}, dy[4] = {0, 1, 0, 1};
	int sx[3], sy[3];
	if (n == 2) {
		int t = 0;
		for(int i = 0; i < 4; i++) {
			if(x + dx[i] == a && y + dy[i] == b) continue;
			sx[t] = x+dx[i], sy[t++] = y + dy[i];
		}
		Report(sx[0], sy[0], sx[1], sy[1], sx[2], sy[2]);
		return;
	}
	n /= 2;
	int t = 0;
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i] * n, cy = y + dy[i] * n;
		if(a >= cx && a < cx+n && b >= cy && b < cy+n) {
			sol(n, cx, cy, a, b);
		}
		else {
			sx[t] = x + n-1+dx[i];
			sy[t] = y + n-1+dy[i];
			sol(n, cx, cy, sx[t], sy[t]);
			t++;
		}
	}
	Report(sx[0], sy[0], sx[1], sy[1], sx[2], sy[2]);
}
void solve(int N, int X, int Y) {
	sol(N, 1, 1, X, Y);
}
main() {
	int n,x,y;
	cin >> n >> x >> y;
	solve(n, x, y);
}