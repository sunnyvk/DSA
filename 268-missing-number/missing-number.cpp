class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,sumofall=0;
        int n=nums.size();
         for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<=n;i++){
            sumofall+=i;
        }
        return sumofall-sum;
    }
};