#include <bits/stdc++.h>
#define N 1010
using namespace std;
struct status {
    int x, y, color;
};
queue<status> qq;
int cot[8], MX[8], MAP[N][N], X[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, Y[8] = {0, 1, 1, 1, 0, -1, -1, -1}, t, n;
void BFS() {
    while (!qq.empty()) {
        status cur = qq.front();
        qq.pop();
        for (int i = 0; i < 8; i++)
            if (cot[i] > MX[i])
                MX[i] = cot[i];
        for (int i = 0; i < 8; i++) {
            int new_x = cur.x + X[i], new_y = cur.y + Y[i];
            if ((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n)) {
                if ((MAP[new_x][new_y] & cur.color) == 0) {
                    cot[MAP[new_x][new_y]]--;
                    MAP[new_x][new_y] |= cur.color;
                    cot[MAP[new_x][new_y]]++;
                    qq.push((status){new_x, new_y, cur.color});
                }
            }
        }
    }
    return;
}
int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        memset(MX, 0, sizeof MX);
        memset(cot, 0, sizeof cot);
        memset(MAP, 0, sizeof MAP);
        cin >> n;
        int x, y, color;
        char c;
        for (int i = 0; i < 3; i++) {
            cin >> c >> x >> y;
            if (c == 'R')
                color = 4;
            else if (c == 'Y')
                color = 2;
            else
                color = 1;
            qq.push((status){x, y, color});
            MAP[x][y] = color;
        }
        cot[1] = cot[2] = cot[4] = 1;
        BFS();
        cin >> c;
        if (c == 'R')
            color = 4;
        else if (c == 'Y')
            color = 2;
        else if (c == 'B')
            color = 1;
        else if (c == 'O')
            color = 6;
        else if (c == 'G')
            color = 3;
        else if (c == 'P')
            color = 5;
        else if (c == 'D')
            color = 7;
        cout << MX[color] << "\n";
    }
}