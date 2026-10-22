class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }
        if (totalsum % 2)
            return false;
        int target = totalsum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
        for (int ind = 0; ind < n; ind++) {
            dp[ind][0] = true;
        }
        if(nums[0]==target){
        dp[0][nums[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            bool take = false;
            bool notake = false;
            for (int k = 1; k <= target; k++) {
                if (k >= nums[ind]) {
                    take = dp[ind - 1][k - nums[ind]];
                }
                notake = dp[ind - 1][k];
                dp[ind][k] = take || notake;
            }
            
        }

        return dp[n - 1][target];
    }
};