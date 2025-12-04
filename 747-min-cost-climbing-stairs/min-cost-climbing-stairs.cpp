class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int ind = 2; ind < n; ind++) {
            int left = cost[ind] + dp[ind - 1];
            int right = cost[ind] + dp[ind - 2];
            dp[ind] = min(left, right);
        }
        return min(dp[n-1], dp[n-2]);
    }
};