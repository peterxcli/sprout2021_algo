#include <bits/stdc++.h>

using namespace std;

int N, k[1010], ch[1010][1010];

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int cnt = 1;
    while (cin >> N) {
        cout << "Line #" << cnt << "\n";
        map<int, int> peopleclassify, grouplastpeople;
        map<int, list<int>::iterator> peoplepos;
        for (int i = 0; i < N; i++) {
            cin >> k[i];
            for (int j = 0; j < k[i]; j++) {
                cin >> ch[i][j];
                peopleclassify[ch[i][j]] = i;
            }
        }
        string oper;
        list<int> lst;
        while (cin >> oper && oper != "STOP") {
            if (oper == "ENQUEUE") {
                int series;
                cin >> series;

            }
            else {
                cout << lst.front() << "\n";
                lst.pop_front();
            }
        }
        cnt ++;
    }
}