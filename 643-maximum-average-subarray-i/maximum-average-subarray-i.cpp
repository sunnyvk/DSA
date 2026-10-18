class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int sum=0,ans=INT_MIN;
        while(r<n){
            sum+=nums[r];
            if((r-l+1)==k){
                ans=max(ans,sum);
                sum-=nums[l];
                l++; 
            }
            r++;
        }
        return (double)ans/k;
    }
};