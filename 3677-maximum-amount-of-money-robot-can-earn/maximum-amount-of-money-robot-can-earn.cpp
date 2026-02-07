class Solution {
public:
int dp[501][501][3];
    int maximumAmount(vector<vector<int>>& coins) {
        
                     int n = coins.size();
        int m = coins[0].size();
         for (int i = 0; i < 501; i++)
            for (int j = 0; j < 501; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = INT_MIN;

         for (int neu = 0; neu <= 2; neu++) {
            if (neu > 0 && coins[n-1][m-1] < 0)
                dp[n-1][m-1][neu] = 0;
            else
                dp[n-1][m-1][neu] = coins[n-1][m-1];
        }
          for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) continue;
                     for (int neu = 0; neu <= 2; neu++) {

                    int best = INT_MIN;

                   
                    if (i + 1 < n)
                        best = max(best, coins[i][j] + dp[i + 1][j][neu]);
                    if (j + 1 < m)
                        best = max(best, coins[i][j] + dp[i][j + 1][neu]);

                 
                    if (neu > 0 && coins[i][j] < 0) {
                        if (i + 1 < n)
                            best = max(best, dp[i + 1][j][neu - 1]);
                        if (j + 1 < m)
                            best = max(best, dp[i][j + 1][neu - 1]);
                    }

                    dp[i][j][neu] = best;
                }
            }
            }
      return dp[0][0][2];
    }
};