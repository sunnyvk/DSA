class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         int n=nums.size();
         if(n==1) return 1;
         int prev_diff=nums[1]-nums[0];
         int count=(prev_diff!=0)?2:1;
         for(int i=2;i<n;i++){
            int curr_diff=nums[i]-nums[i-1];
            if((curr_diff>0 && prev_diff<=0) || (curr_diff<0 && prev_diff>=0)){
                count++;
                prev_diff=curr_diff;
            }
         }
         return count;
    }
};