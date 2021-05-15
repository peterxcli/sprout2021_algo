#include <bits/stdc++.h>
#define int long long
using namespace std;

int largestRectangleArea(vector<int> height) {
    int result = 0;
    height.push_back(0);
    stack<int> s;
    for (int i = 0; i < height.size(); ++i) {
        while (!s.empty() && height[s.top()] >= height[i]) {
            int area;
            s.pop();
            if (s.empty()) area = height[s.top()] * i;
            else area = height[s.top()] * (i-s.top()-1);
            result = max(result, area);
        }
        s.push(i);
    }
    return result;
}

int32_t main() {
    cin.tie(), ios_base::sync_with_stdio(0);
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << largestRectangleArea(a) << "\n";
}