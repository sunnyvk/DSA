class Solution {
public:
   int solve(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return nums[0];
        if(ind == 1) return max(nums[0], nums[1]);

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + solve(ind-2, nums, dp);
        int nottake = solve(ind-1, nums, dp);

        return dp[ind] = max(take, nottake);
    }
int maxAdjacentSum(vector<int>& nums){
     int n = nums.size();
    if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n, -1);
        return solve(n-1, nums, dp);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
          if(n == 1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(maxAdjacentSum(temp1),maxAdjacentSum(temp2));
    }
};