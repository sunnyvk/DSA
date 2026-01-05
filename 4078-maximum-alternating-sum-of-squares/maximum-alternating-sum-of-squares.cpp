class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
      int w=n/2;
        long long ans=0;
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<w;i++){
           ans-=nums[i]*nums[i];
        }
         for(int i=w;i<n;i++){
           ans+=nums[i]*nums[i];
        }        
        return ans;
    }
};