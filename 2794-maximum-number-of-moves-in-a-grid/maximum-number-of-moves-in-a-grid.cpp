class Solution {
public:
int solve(vector<vector<int>>& grid,int row,int col, int n,int m, vector<vector<int>>& dp){
    if(row<0 || row>n ||col >m) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    int updig=0,right=0,downdig=0;
    if(row-1>=0 && col+1<m && grid[row-1][col+1]>grid[row][col]){
        updig=1+solve(grid,row-1,col+1,n,m,dp);
    }
      if(col+1<m && grid[row][col+1]>grid[row][col]){
        right=1+solve(grid,row,col+1,n,m,dp);
    }
      if(row+1<n && col+1<m && grid[row+1][col+1]>grid[row][col]){
        downdig=1+solve(grid,row+1,col+1,n,m,dp);
    }
    return dp[row][col]=max(updig,max(right,downdig));

}
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0;i<n;i++){
            int res=solve(grid,i,0,n,m,dp);
            ans=max(ans,res);
        } 
        return ans;  
    }
};