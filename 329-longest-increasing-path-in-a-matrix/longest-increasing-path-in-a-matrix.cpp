class Solution {
public:
    int m, n;
    vector<vector<int> > dp;
    vector<vector<int>> directions = {
                {-1,0},
        {0,-1},         {0,1},
                {1, 0}
    };
    
    bool isSafe(int i, int j) {
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    
    long long MOD = 1e9+7;
    
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        
        int answer = 1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(isSafe(i_, j_) && matrix[i_][j_] < matrix[i][j]) {
                answer = max(answer ,1+dfs(matrix, i_, j_)) ;
            }
        }
        
        return dp[i][j]=answer;
        
    }
    
     int longestIncreasingPath(vector<vector<int>>& matrix) {
        m= matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1)); 

        int result = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                result =max(result , dfs(matrix, i, j));
            }
        }
         
        return result;
    }
};
