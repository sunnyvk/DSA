class Solution {
    int n,m;
    vector<pair<int,int>> directions={{1,-1},{1,0},{1,1}};
    vector<vector<int>> dp;
  int solve(int i,int j,vector<vector<int>>& matrix){
    int result=INT_MAX;
    if(j<0 || j>=m) return INT_MAX;
    if(i==0){
       return matrix[0][j];
    }
    if (dp[i][j] != INT_MAX)   
            return dp[i][j];
        for(auto dir:directions){
            int new_r=i-dir.first;
            int new_c=j-dir.second;

             int prev = solve(new_r, new_c, matrix);

            if (prev != INT_MAX) {
              
                result = min(result, matrix[i][j] + prev);
            }
        }
        return dp[i][j]=result;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n=matrix.size();
         m=matrix[0].size();
         dp.assign(n, vector<int>(m, INT_MAX));
       int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, solve(n - 1, j, matrix));
        }
        return ans;
    }
};