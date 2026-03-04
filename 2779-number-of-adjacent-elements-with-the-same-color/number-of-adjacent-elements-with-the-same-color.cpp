class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n,0),result;
        int count=0;
        for(auto query:queries){
            int i=query[0],color=query[1];
            if(nums[i] && i - 1 >= 0 && nums[i-1] == nums[i]) count--;  
            if(nums[i] && i + 1 < n && nums[i+1] == nums[i]) count--;
            nums[i] = color;
            if(i-1>=0 && nums[i-1]==nums[i]) count++;
            if(i+1<n && nums[i+1]==nums[i]) count++;
            result.push_back(count);
        }
        return result;
    }
};