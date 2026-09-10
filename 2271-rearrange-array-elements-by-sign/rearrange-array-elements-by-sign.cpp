class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans1;
        vector<int> ans2;
         vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans2.push_back(nums[i]);
            }else{
                ans1.push_back(nums[i]);
            }
        }
             for(int i=0;i<n/2;i++){
                ans.push_back(ans1[i]);
                ans.push_back(ans2[i]);
             }
             return ans;
    }
};