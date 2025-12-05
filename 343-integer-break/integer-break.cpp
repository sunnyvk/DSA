class Solution {
public:
    int integerBreak(int n) {
      
        vector<int> dp(n+1,-1);
        dp[1]=1;
      
        for (int i = 2; i <= n; i++) {
              int result = INT_MIN;
               for (int j = 1;j <i; j++){
                      int prod = j* max(i- j, dp[i - j]);
                      result = max(result, prod);
               }
          dp[i]=result;
            
        }
        return dp[n];

    }
};