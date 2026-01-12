class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            unordered_map<int, int> mpp;
            int ans = INT_MAX;
            int count = 0;
            for (int j = i; j < n; j++) {
                mpp[nums[j]]++;
                if (mpp[nums[j]] == 2) {
                    count += 2;
                }
                if (mpp[nums[j]] > 2) {
                    count++;
                }
                dp[i] = min(dp[i], k + dp[j + 1] + count);
            }
        
        }
        return dp[0];
    }
};