class Solution {

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int prev=nums[0];
        int prev2=0;
        for(int ind=1;ind<n;ind++){
             int pick=nums[ind];
             if(ind>1)
             pick+=prev2;
          int notpick=0+prev;
          int cur=max(pick,notpick); 
          prev2=prev;
          prev=cur;
        }
       return prev;
        
    }
};