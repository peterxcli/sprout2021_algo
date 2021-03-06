#include <bits/stdc++.h>

using namespace std;

vector<int> A_order, B_order;

int main() {
    string A, B;
    cin >> A >> B;
    int ans = 0, len = A.size(), cnt = 1;
    for (int i = 1; i < len; i++) {
        if (A[i] == A[i-1]) cnt++;
        if (A[i] != A[i-1] || i == len-1) A_order.push_back(cnt), cnt = 1;
    }

    for (int i = 0; i < A_order.size(); i++) {
        cout << A_order[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < len; i++) {
        int cnt = 1, check = 1;
        B_order.clear();
        for (int j = 1; j < len; j++) {
            if (B[i] == B[i-1]) cnt++;
            if (B[j] != B[j-1] || j == len-1) B_order.push_back(cnt), cnt = 1;
        }
        cout << B << endl;
        for (int i = 0; i < B_order.size(); i++) {
            cout << B_order[i] << " ";
        }
        cout << endl;
        if (A_order.size() != B_order.size()) continue;
        for (int j = 0; j < A_order.size(); j++) {
            if (A_order[j] != B_order[j]) {
                check = 0;
                break;
            }
        }
        if (check){ ans++; }
        B.insert(B.begin(), B[B.size()-1]); 
        // B.erase(B.size()-1);
    }
    cout << ans << endl;
}