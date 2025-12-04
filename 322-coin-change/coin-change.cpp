class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        for (int a = 0; a <= amount; a++) {
            if (a % coins[0] == 0) {
                dp[0][a] = a / coins[0];
            } else {
                dp[0][a] = 1e9;
            }
        }

        for (int ind = 1; ind <= n - 1; ind++) {
            for (int a = 0; a <= amount; a++) {
                int nottake = dp[ind - 1][a];
                int take = INT_MAX;
                if (coins[ind] <= a)
                    take = 1 + dp[ind][a - coins[ind]];
                dp[ind][a] = min(take, nottake);
            }
        }
        int ans=dp[n - 1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};