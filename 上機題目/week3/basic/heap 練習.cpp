#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    __gnu_pbds::priority_queue<int, greater<int>> pq;
    int T;
    cin >> T;
    while(T--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int n;
            cin >> n;
            pq.push(n);
        }
        else {
            if (pq.empty()) cout << "empty!\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}