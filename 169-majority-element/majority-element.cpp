class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        for (auto it : mp) {
            if (it.second > n / 2) {
                ans=it.first;
            }
        }
        return ans;
    }
};