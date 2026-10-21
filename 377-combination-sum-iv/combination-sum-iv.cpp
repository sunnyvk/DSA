
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int t = 1; t <= target; t++) {
            for (int x : nums) {
                if (x > t) break;
                dp[t] += dp[t - x];
            }
        }

        return dp[target];
    }
};

