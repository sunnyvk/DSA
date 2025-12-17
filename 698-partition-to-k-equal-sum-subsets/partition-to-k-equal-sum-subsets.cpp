class Solution {
public:
    bool solve(int idx, vector<int>& nums, vector<bool>& used,
               int k, int currSum, int target) {

        if (k == 1) return true;          // last bucket auto valid
        if (currSum == target)
            return solve(0, nums, used, k - 1, 0, target);

        for (int i = idx; i < nums.size(); i++) {
            if (used[i] || currSum + nums[i] > target) continue;

            used[i] = true;
            if (solve(i + 1, nums, used, k, currSum + nums[i], target))
                return true;
            used[i] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        int target = total / k;
        sort(nums.rbegin(), nums.rend());   // small optimization

        vector<bool> used(nums.size(), false);
        return solve(0, nums, used, k, 0, target);
    }
};
