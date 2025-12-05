class Solution {
 
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if( totalsum%2!=0) return false;
         int target=totalsum/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0] <= target)
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                bool nottake=dp[i-1][t];
                bool take=false;
                if(nums[i]<=t) take=dp[i-1][t-nums[i]];
                dp[i][t]=take || nottake ;
            }
        }
        return dp[n-1][target];
    }
};