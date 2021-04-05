//https://vjudge.net/problem/51Nod-1091
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int> > segment(N);
    for (int i = 0; i < N; i++) cin >> segment[i].first >> segment[i].second;
    sort(segment.begin(), segment.end());
    int ans = 0, old_right_max = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, abs(segment[i].first-min(segment[i].second, old_right_max)));
        old_right_max = max(old_right_max, segment[i].second);
    }
    cout << ans << "\n";
    return 0;
}