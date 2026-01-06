class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=k;;i+=k)
             if (find(nums.begin(), nums.end(), i) == nums.end())
                return i;
            
                    
    }
};