class Solution {

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int ind=1;ind<n;ind++){
             int pick=nums[ind];
             if(ind>1)
             pick+=dp[ind-2];
          int notpick=0+dp[ind-1];
          dp[ind]=max(pick,notpick); 
        }
       return dp[n-1];
        
    }
};