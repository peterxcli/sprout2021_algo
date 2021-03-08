#include <bits/stdc++.h>

using namespace std;

int N, k, group_last[1010], group[10000000];

list<int>::iterator last[1010];

list<int> QQ;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int cnt = 1;
    while (cin >> N) {
        fill(group_last, group_last+1010, -1);
        fill(group, group+10000000, -1);
        fill(last, last+1010, QQ.end());
        cout << "Line #" << cnt << "\n";
        for (int i = 0; i < N; i++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                int tmp;
                cin >> tmp;
                group[tmp] = i;
            }
        }
        string oper;
        list<int> lst;
        while (cin >> oper && oper != "STOP") {
            if (oper == "ENQUEUE") {
                int series;
                cin >> series;
                if (group[series] == -1) {
                    lst.emplace_back(series);
                }
                else if (last[group[series]] == QQ.end()) {
                    last[group[series]] = lst.insert(lst.end(), series);
                }
                else {
                    last[group[series]] = lst.insert(next(last[group[series]]), series);
                }
            }
            else {
                cout << lst.front() << "\n";
                if(group[lst.front()] != -1 && *last[group[lst.front()]] == lst.front()) {
                    last[group[lst.front()]] = QQ.end();
                }
                lst.pop_front();
            }
        }
        cnt ++;
    }
}