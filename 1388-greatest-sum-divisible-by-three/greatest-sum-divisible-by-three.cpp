class Solution {

public:
    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        dp[n][0] = 0;
        dp[n][1] = INT_MIN;
        dp[n][2] = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            for (int rem = 0; rem <= 2; rem++) {
                int take = (dp[i + 1][(rem + nums[i]) % 3] == INT_MIN)
                               ? INT_MIN
                               : (nums[i] + dp[i + 1][(rem + nums[i]) % 3]);
                int skip = dp[i + 1][rem];
                dp[i][rem] = max(take, skip);
            }
        }
        return dp[0][0];
    }
};