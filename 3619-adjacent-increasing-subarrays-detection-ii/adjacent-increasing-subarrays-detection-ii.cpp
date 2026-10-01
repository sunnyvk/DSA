class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int curr=1,prev=0,res=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }else{
                res=max({res,curr/2,min(curr,prev)});
                prev=curr;
                curr=1;
            }
        }
        res=max({res,curr/2,min(curr,prev)});
        return res;
    }
};