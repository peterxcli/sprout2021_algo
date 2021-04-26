//https://tioj.ck.tp.edu.tw/problems/1080
//codeforces template
#define MANY_SUBTASK
#define lowbit(x) -x&x
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int t = 1, N;

const int mod = 10000019;

vector<int> BIT, num;

void modify(int pos, int val) {
    for (int idx = pos; idx <= N; idx += lowbit(idx)){
		BIT[idx] += val, BIT[idx] %= mod;
		num[idx] += 1;
	}
}

int queryNum(int pos) {
    int ret = 0;
    for (int idx = pos; idx; idx -= lowbit(idx))
        ret += num[idx];
    return ret;
}

int query(int pos) {
    int ret = 0;
    for (int idx = pos; idx; idx -= lowbit(idx))
        ret += BIT[idx], ret %= mod;
    return ret;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
    else return a.first > b.first;
}

void solve_subtask() {
    vector<pair<int, int> > a;
    a.resize(N);
    BIT.resize(N+1, 0), num.resize(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    modify(a[0].second, a[0].first);
    for (int i = 1; i < N; i++) {
        ans += query(a[i].second) + queryNum(a[i].second)*a[i].first;
		ans %= mod;
        modify(a[i].second, a[i].first);
    }
	cout << ans << "\n";
    a.clear(), BIT.clear();
}
int32_t main() {
    cin.tie(NULL), ios_base::sync_with_stdio(0);
    while (cin >> N) {
        solve_subtask();
    }
    return 0;
}