class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.second>n/2){
                ans=it.first;
            }
        }
        return ans;
    }
};