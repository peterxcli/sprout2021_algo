#include <bits/stdc++.h>

#pragma GCC optimize(3, "Ofast", "inline")

using namespace std;

int ans, vis[1005][1005], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int H, W;
char grid[1005][1005];

void dfs(int x, int y) {
    if (grid[y][x] == '#') return;
    for (int i = 0; i < 4; i++) {
        int next_x = x+dir[i][0], next_y = y+dir[i][1];
        if (next_x >= 0 && next_x < W && next_y >= 0 && next_y < H && !vis[next_y][next_x] && grid[next_y][next_x] == '.') {
            vis[next_y][next_x] = true;
            dfs(next_x, next_y);
        }
    }
}

struct state{
    int x, y;
};

void bfs(int x, int y) {
    if (grid[y][x] == '#') return;
    queue<state> q;
    q.push({x, y});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = cur.x+dir[i][0], next_y = cur.y+dir[i][1];
            if (next_x >= 0 && next_x < W && next_y >= 0 && next_y < H && !vis[next_y][next_x] && grid[next_y][next_x] != '#') {
                vis[next_y][next_x] = true;
                q.push({next_x, next_y});
            }
        }
    }
}

void solve() {
    ans = 0;
    memset(vis, 0, sizeof(vis));
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!vis[i][j] && grid[i][j] == '.') ans ++;
            // dfs(j, i);
            bfs(j, i);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}