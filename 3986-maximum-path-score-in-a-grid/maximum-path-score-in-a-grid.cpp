class Solution {
public:
int solve(int i,int j,vector<vector<int>>& grid,int k,vector<vector<vector<int>>>& dp){
     int m=grid.size();
        int n=grid[0].size();
        if(k<0){
            return -1e9;
        }
        if(i==m || j==n){
            return -1e9;
        }
         if(i==m-1 && j==n-1){
            if(min(grid[i][j],1)<=k){
                return grid[i][j];
            }else{
                return -1e9;
            }
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int right=grid[i][j]+solve(i,j+1,grid,k-min(grid[i][j],1),dp);
        int down=grid[i][j]+solve(i+1,j,grid,k-min(grid[i][j],1),dp);
        return dp[i][j][k]=max(right,down);

}
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (k+1,-1)));
        int ans=solve(0,0,grid,k,dp);
        if(ans<0){
            return -1;
        }
        return ans;
    }
};