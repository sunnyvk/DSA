class Solution {
//    int solve(int ind,int amount,vector<int>& coins){
//         if(ind==0){
//             return (amount%coins[0]==0);
//         }
//         int nottake=solve(ind-1,amount,coins);
//         int take=0;
//         if(coins[ind]<=amount)
//         take=solve(ind,amount-coins[ind],coins);
//         return nottake+take;
//     }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        for(int t=0;t<=amount;t++){
           if(t%coins[0]==0){
             dp[0][t]=1;
           }
        }
        for(int ind=1;ind<=n-1;ind++){
           for(int t=0;t<=amount;t++){
        long long nottake=dp[ind-1][t];
        long long take=0;
        if(coins[ind]<=t)
        take=dp[ind][t-coins[ind]];
        dp[ind][t]= nottake+take;
           }
             
        }
        return dp[n-1][amount];
    }
};