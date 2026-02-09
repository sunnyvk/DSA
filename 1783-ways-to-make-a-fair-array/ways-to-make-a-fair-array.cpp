class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int res = 0;
        int n =nums.size();
        int righteven = 0, rightodd = 0;
        
        for(int i=0; i<n; ++i) {
            if(i%2 == 0) righteven += nums[i];
            else rightodd += nums[i];
        }
        
        int lefteven = 0, leftodd = 0;
        for(int i=0; i<n; ++i) {
            
            if(i%2 == 0) {
                righteven -= nums[i];
            } else {
                rightodd -= nums[i];
            }
            
            if(lefteven + rightodd == leftodd + righteven)
                ++res;
            
            if(i%2== 0) {
                lefteven += nums[i];
            } else {
                leftodd += nums[i];
            }
        }
        
        return res;
    }
};