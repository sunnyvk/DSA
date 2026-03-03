class Solution {
public:

    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int left=0,right=0;
        int count=0;
        while(right<nums.size()){
            if(nums[right]==maxi) count++;
            while(count>=k){
                if(nums[left]==maxi)  count--;
                left++;
                ans+=nums.size()-right;
            }
             right++;
        }
       return ans;
           }
};