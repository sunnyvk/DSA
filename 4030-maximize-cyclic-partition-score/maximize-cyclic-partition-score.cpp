class Solution {
public:
    int const MOD = 1e9 + 7;
    long long const INF = 1e18;
    vector<vector<long long>> dp[3];
    long long rec(vector<int>& nums, int mode, int k, int i) {
        // mode=0 means just started
        // mode=1 means have min
        // mode=2 means  have max
        int const n = nums.size();
        if (i >= n)
            return mode ? -INF : 0;
        else if (dp[mode][k][i] != -1)
            return dp[mode][k][i];
        else {
            long long res = rec(nums, mode, k, i + 1);
            if (mode == 0 && k) {
                res = max(res, -nums[i] + rec(nums, 1, k, i));
                res = max(res, +nums[i] + rec(nums, 2, k, i));
            }
            if (mode == 1)
                res = max(res, +nums[i] + rec(nums, 0, k - 1, i + 1));
            if (mode == 2)
                res = max(res, -nums[i] + rec(nums, 0, k - 1, i + 1));
            return dp[mode][k][i] = res;
        }
    }
    long long solve(vector<int>& nums, int k) {
        int const n = nums.size();
        dp[0] = dp[1] = dp[2] =
            vector<vector<long long>>(k + 1, vector<long long>(n + 1, -1));
        return rec(nums, 0, k, 0);
    }

    long long maximumScore(vector<int>& nums, int k) {
        int const n = nums.size(),
                  idx = min_element(nums.begin(), nums.end()) - nums.begin();
        rotate(nums.begin(), nums.begin() + idx, nums.end());
        long long res_l = solve(nums, k);
        rotate(nums.begin(), nums.begin() + 1, nums.end());
        long long res_r = solve(nums, k);
        return max(res_l, res_r);
    }
};