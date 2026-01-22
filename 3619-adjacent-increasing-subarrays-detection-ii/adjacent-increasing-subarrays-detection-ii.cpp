class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int res=0,prev=0,curr=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }else{
                res=max({res,curr/2,min(prev,curr)});
                prev=curr;
                curr=1;
            }
        }
         res=max({res,curr/2,min(prev,curr)});
         return res;
    }
};