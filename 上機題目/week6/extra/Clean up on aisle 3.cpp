//https://tioj.ck.tp.edu.tw/problems/1500
//https://tioj.ck.tp.edu.tw/submissions/249466
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
vector<pair<int, int> > points;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
double getDistance(pair<int, int> a, pair<int, int> b) {
    return sqrt(double(a.first-b.first)*(a.first-b.first) + double(a.second-b.second)*(a.second-b.second));
}
double solve(int l, int r) {
    if (l == r) return INT32_MAX;
    if(l == r-1) return getDistance(points[l], points[r]);
    int m = (l+r)>>1;
    double ret = min(solve(l, m), solve(m+1, r));
    vector<pair<int, int>> lp, rp;
    for (int i = m; i >= l; i--) {
        if (points[m].first - points[i].first > ret) break;
        lp.emplace_back(points[i]);
    }
    for (int i = m+1; i <= r; i++) {
        if (points[i].first - points[m+1].first > ret) break;
        rp.emplace_back(points[i]);
    }
    sort(lp.begin(), lp.end(), cmp);sort(rp.begin(), rp.end(), cmp);
    for (auto a:lp) {
        for (auto b:rp) {
            ret = min(getDistance(a, b), ret);
        }
    }
    return ret;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while(cin >> N) {
        cout << fixed << setprecision(6);
        points.resize(N);
        for (int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
        sort(points.begin(), points.end());
        cout << solve(0, N-1) << "\n";
    }
    return 0;
}