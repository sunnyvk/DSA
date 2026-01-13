class Solution {
public:
    int MOD = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);
        dp[0] = 0;
        pref[0] = 1;
        deque<int> minDeque, maxDeque;
        int i = 0, j = 0;
        while (j < n) {
            while (!maxDeque.empty() && nums[j] > nums[maxDeque.back()]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(j);
            while (!minDeque.empty() && nums[j] < nums[minDeque.back()]) {
                minDeque.pop_back();
            }
            minDeque.push_back(j);
            while (i <= j &&
                   nums[maxDeque.front()] - nums[minDeque.front()] > k) {
                i++;
                if (!maxDeque.empty() && maxDeque.front() < i)
                    maxDeque.pop_front();
                if (!minDeque.empty() && minDeque.front() < i)
                    minDeque.pop_front();
                   }
                dp[j + 1] = (pref[j] - (i > 0 ? pref[i - 1] : 0) + MOD) % MOD;
                pref[j + 1] = (pref[j] + dp[j + 1]) % MOD;
                j++;
            
        }
        return dp[n];
    }
};