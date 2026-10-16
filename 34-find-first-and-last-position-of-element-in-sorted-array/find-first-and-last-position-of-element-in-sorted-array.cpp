class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int ans1 = -1;
        int low1 = 0, high1 = n - 1;
        while (low1 <= high1) {
            int mid = (low1 + high1) / 2;
            if (nums[mid] >= target) {
                high1 = mid - 1;

            } else {
                low1 = mid + 1;
            }
            if(nums[mid]==target)   ans1 = mid;
        }
        int ans2 = -1;
        int low2 = 0, high2 = n - 1;
        while (low2 <= high2) {
            int mid = (low2 + high2) / 2;
            if (nums[mid] > target) {
                 high2 = mid - 1;
         
            } else {
                      low2 = mid + 1;
            }
             if(nums[mid]==target)  ans2 = mid;
        }
        return {ans1, ans2};
    }
};