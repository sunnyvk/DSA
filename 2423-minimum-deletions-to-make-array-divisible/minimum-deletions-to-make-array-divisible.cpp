class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map<int,int> mpp;

        // Count frequency (same as your code)
        for (auto it : nums) {
            mpp[it]++;
        }

        // 🔥 FIX 1: Compute GCD instead of sum
        int g = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); i++) {
            g = __gcd(g, numsDivide[i]);
        }

        // 🔥 FIX 2: Sort nums to ensure smallest first
        sort(nums.begin(), nums.end());

        int deletions = 0;

        // 🔥 FIX 3: Traverse sorted nums
        for (auto it : nums) {
            if (g % it == 0) {
                return deletions;  // found smallest valid element
            }
            deletions++;
        }

        return -1;
    }
};
