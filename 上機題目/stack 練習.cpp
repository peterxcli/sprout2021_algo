#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    stack<int> s;
    while (T--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int n;
            cin >> n;
            s.push(n);
        }
        else {
            if (!s.empty()) {
                cout << s.top() << "\n";
                s.pop();
            }
            else {
                cout << "empty!\n";
            }
        }
    }
}