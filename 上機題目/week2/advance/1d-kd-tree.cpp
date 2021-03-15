#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    set<int> st;
    while (N--) {
        string oper;
        int input;
        cin >> oper >> input;
        if (oper[0] == 'i') {
            st.insert(input);
        }
        else if (oper[0] == 'd') {
            st.erase(input);
        }
        else {
            auto ret = st.find(input);
            if (ret != st.end()) {
                cout << input << "\n";
                continue;
            }
            auto tmp = st.insert(input);
            auto iter = tmp.first;
            if (iter == st.begin()) {
                cout << *next(iter) << "\n";
            }
            else if (iter == prev(st.end())) {
                cout << *prev(iter) << "\n";
            }
            else {
                if (abs(*prev(iter)-input) == abs(*next(iter)-input)) {
                    cout << *prev(iter) << " " << *next(iter) << "\n";
                }
                else cout << (abs(*prev(iter)-input) > abs(*next(iter)-input)?*next(iter):*prev(iter)) << "\n";
            }
            st.erase(input);
        }
    }
}