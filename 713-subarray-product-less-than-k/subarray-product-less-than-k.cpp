class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int left=0,right=0;
        int product=1;
        if(k<=1) return 0;
        int n=nums.size();
        while(right<n){
            product=product*nums[right];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            ans+=(right-left+1);
            right++;
        }
        return ans;
    }
};