// http://nphard001.blogspot.com/2011/11/zjb242.html
// http://eazyrealcode.blogspot.com/2015/03/toj-22.html

// ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^    ^
// |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
// 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 題解 

//https://neoj.sprout.tw/problem/22/

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        int n, ans = 0;
        cin >> n;
        // vector<int> a(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            while (!s.empty() && tmp > s.top()) s.pop();
            s.push(tmp);
        }
    }
}