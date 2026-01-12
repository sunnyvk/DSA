class Solution {
public:
    int MOD = 1000000007;
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int prevIndex, int mask) {
        // Base case: all elements used
        if (mask == (1 << nums.size()) - 1) {
            return 1;
        }

        // Memoization check
        if (dp[prevIndex + 1][mask] != -1)
            return dp[prevIndex + 1][mask];

        int ways = 0;

        for (int j = 0; j < nums.size(); j++) {
            // if already used
            if (mask & (1 << j)) continue;

            // divisibility condition
            if (prevIndex == -1 ||
                nums[prevIndex] % nums[j] == 0 ||
                nums[j] % nums[prevIndex] == 0) {

                ways = (ways + solve(nums, j, mask | (1 << j))) % MOD;
            }
        }

        return dp[prevIndex + 1][mask] = ways;
    }

    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1, vector<int>(1 << n, -1));
        return solve(nums, -1, 0);
    }
};
