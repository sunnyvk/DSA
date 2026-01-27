class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        dist[0][0]=1;
        q.push({1, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
             if (r == n - 1 && c == m - 1) {
                            return dist[r][c];
                        }
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if(dr==0 && dc==0) continue;
                    int newr = r + dr;
                    int newc = c + dc;
                    if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                        grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                        dist[newr][newc] = dis + 1;
                        q.push({dis + 1, {newr, newc}});
                    }
                }
            }
        }
        return -1;
    }
};