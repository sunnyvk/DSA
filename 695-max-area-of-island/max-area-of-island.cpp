class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int cnt = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    cnt++;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int res = bfs(i, j, grid, vis);
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};