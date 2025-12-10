class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int transactionNo = 2 * k - 1; transactionNo >= 0;
                 transactionNo--) {
                if (transactionNo % 2 == 0) {
                    dp[i][transactionNo] =
                        max(-prices[i] + dp[i + 1][transactionNo + 1],
                            dp[i + 1][transactionNo]);
                } else {
                    dp[i][transactionNo] =
                        max(prices[i] + dp[i + 1][transactionNo + 1],
                            dp[i + 1][transactionNo]);
                }
            }
        }
            return dp[0][0];
        }
    };