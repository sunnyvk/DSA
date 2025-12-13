class Solution {
public:
int solve(int i,vector<int>& nums,vector<int> &dp){
    if(i<2) return 0;
    int cnt=0;
    if(dp[i]!=-1) return dp[i];
    if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
        cnt=1+solve(i-1,nums,dp);
    }
    return dp[i]=cnt;
}
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> dp(n+1,-1);
        for(int i=2;i<n;i++){
                ans+=solve(i,nums,dp);
        }
        return ans;
    }
};