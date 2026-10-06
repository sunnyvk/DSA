class Solution {
public:

    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        while(nums[0]>0){
            int count[10]={};
            for(int i=0;i<n;i++){
                int digit=nums[i]%10;
                ans+=i-count[digit];
                count[digit]++;
                nums[i]/=10;
            }
        }
        return ans;
    }
};