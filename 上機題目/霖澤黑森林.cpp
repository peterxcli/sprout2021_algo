#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int a[MAXN];

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int n, flag = 1;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            s.push(tmp);
        }
        else {
            // if (s.empty()) continue;
            if (!s.empty() && s.top() == -tmp) s.pop();
            else flag = 0;
        }
    }
    if (flag == 1 && s.empty()) cout << "weed\n";
    else cout << "lose light light\n";
}