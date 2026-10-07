class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        long long lsum=0,rsum=0;
        int l=0,r=n-1;
        while(l<n-1 && nums[l]<nums[l+1]){
            lsum+=nums[l++];
        }
          while(r>0 && nums[r-1]>nums[r]){
            rsum+=nums[r--];
        }
        if(l==r){
            long long option1=abs((lsum+nums[l])-rsum);
             long long option2=abs(lsum-(nums[r]+rsum)); 
             return min(option1,option2);
        }else if(nums[l]==nums[r] && r-l==1){
            return abs(lsum-rsum);
        }
        return -1;
    }
};