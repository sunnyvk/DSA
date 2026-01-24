class Solution {
public:
    bool bfs(int row, int col, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2, vector<vector<int>> &vis) {
        int n = grid2.size();
        int m = grid2[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        bool isSubIsland = true;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (grid1[row][col] == 0) {
                isSubIsland = false;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid2[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid2[i][j]==1 && !vis[i][j]){
                    if (bfs(i, j, grid1, grid2, vis)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};