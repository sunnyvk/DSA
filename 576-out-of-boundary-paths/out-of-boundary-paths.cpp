class Solution {
public:
   int M;
    int N;
    int MOD=1e9+7;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
     int  solve(int startRow,int startColumn,int maxMove,vector<vector<vector<int>>> &dp){
        if(startRow<0 || startRow>=M || startColumn<0 || startColumn>=N) return 1;
        if(maxMove<=0){
            return 0;
        }
        if(dp[startRow][startColumn][maxMove]!=-1) return dp[startRow][startColumn][maxMove];
        int result=0;
        for(vector<int> dir:directions){
            int new_row=startRow+dir[0];
            int new_col=startColumn+dir[1];
            result=(result+solve(new_row,new_col,maxMove-1,dp))%MOD;
        }
        return  dp[startRow][startColumn][maxMove]=result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
         M=m;
        N=n;
        vector<vector<vector<int>>> dp(M+1,vector<vector<int>> (N+1,vector<int> (maxMove+1,-1)));
        return solve(startRow,startColumn,maxMove,dp);
    }
};