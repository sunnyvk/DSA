class Solution {
public:
vector<vector<vector<int>>> dp;
  int  solve(int i,int j,int neu,vector<vector<int>>& coins){
        int n=coins.size();
        int m=coins[0].size();
        if(dp[i][j][neu]!=INT_MIN) return dp[i][j][neu];
        if(i>=n || j>=m) return INT_MIN;
        if(i==n-1 && j==m-1){
            if(neu>0 && coins[i][j]<0) return 0;
            else return coins[i][j];
        }
        int take=coins[i][j]+max(solve(i+1,j,neu,coins),solve(i,j+1,neu,coins));
        int nottake=INT_MIN;
        if(neu>0 && coins[i][j]<0){
            nottake=max(solve(i+1,j,neu-1,coins),solve(i,j+1,neu-1,coins));
        }
        return dp[i][j][neu]=max(take,nottake);
    }
    int maximumAmount(vector<vector<int>>& coins) {
           int n=coins.size();
        int m=coins[0].size();
        dp.resize(n+1, vector<vector<int>> (m+1, vector<int> (3,INT_MIN)));
       return solve(0,0,2,coins);
    }
};