class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> count(n, 1); // 1 for subarrays of size 1
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                if (nums[s.top()] == nums[i]) {
                    count[i] += count[s.top()];
                }
                s.pop();
            }
            s.push(i);
        }
        return accumulate(count.begin(), count.end(), 0LL);
    }
};