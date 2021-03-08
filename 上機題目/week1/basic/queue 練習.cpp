#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    queue<int> q;
    while (T--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int n;
            cin >> n;
            q.push(n);
        }
        else {
            if (q.empty()) cout << "empty!\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }
}