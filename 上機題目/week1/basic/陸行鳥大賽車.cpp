#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;

int main() {
    list<int> lst;
    map<int, list<int>::iterator> mp;
    cin.tie(0), ios_base::sync_with_stdio(0);
    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) lst.emplace_back(i);
    for (auto iter = lst.begin(); iter != lst.end(); iter++) mp[*iter] = iter;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int T, X;
        cin >> T >> X;
        if (lst.empty()) continue;
        if (T == 0) {
            auto ret = mp.find(X);
            lst.erase(ret->second);
        }
        else {
            auto ret = mp.find(X);
            auto iter = ret->second;
            if (iter != lst.begin()) {
                auto tmp = *iter;
                mp[*iter] = prev(iter);
                mp[*prev(iter)] = iter;
                *iter = *prev(iter);
                *prev(iter) = tmp;
            }
        }
    }
    cout << lst.front();
    lst.pop_front();
    while (!lst.empty()) {
        cout << " " << lst.front();
        lst.pop_front();
    }
    cout << "\n";
}