class Solution {
    int f(int ind,vector<int> &dp){
        if(ind==0) return 1;
        if(ind==1) return 1;
        int left=dp[ind-1];
        int right=dp[ind-2];
        return dp[ind]=left+right;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
          dp[0]=1;
        dp[1]=1; 
        for(int ind=2;ind<=n;ind++){
               int left=dp[ind-1];
        int right=dp[ind-2];
        dp[ind]=left+right;
        }
         
        return dp[n];
    }
};