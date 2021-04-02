#include <bits/stdc++.h>

using namespace std;

int n, start_x, start_y, end_x, end_y, ans, vis[105][105], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, m;

char grid[105][105];

void dfs(int cur_step, int x, int y) {
    if (grid[y][x] == '@') {
        ans = min(ans, cur_step);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int next_x = x+dir[i][0], next_y = y+dir[i][1];
        if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && !vis[next_y][next_x] && grid[next_y][next_x] != '#') {
            vis[next_y][next_x] = true;
            dfs(cur_step+1, next_x, next_y);
            vis[next_y][next_x] = false;
        }
    }
}

struct state{
    int step, x, y;
};

void bfs() {
    queue<state> q;
    q.push({0, start_x, start_y});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (grid[cur.y][cur.x] == '@') {
            ans = min(ans, cur.step);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int next_x = cur.x+dir[i][0], next_y = cur.y+dir[i][1];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && !vis[next_y][next_x] && grid[next_y][next_x] != '#') {
                vis[next_y][next_x] = true;
                q.push({cur.step+1, next_x, next_y});
            }
        }
    }
}

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    while (cin >> n && n != 0) {
        ans = INT32_MAX;
        // memset(grid, 0, sizeof(grid));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        m = strlen(grid[0]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'K') start_x = j, start_y = i;
            }
        }
        // dfs(0, start_x, start_y);
        bfs();
        if (ans != INT32_MAX) cout << ans << "\n";
        else cout << "= =\"\n";
    }
}