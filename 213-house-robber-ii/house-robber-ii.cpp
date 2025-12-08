class Solution {
       int rob1(vector<int>& nums) {
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
public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};