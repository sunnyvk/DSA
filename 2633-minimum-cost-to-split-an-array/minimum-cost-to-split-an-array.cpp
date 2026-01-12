class Solution {
public:
int n;
int solve(int i,vector<int> &nums,int k, vector<int> &dp){
    if(i==n){
        return 0;
    }
    if(dp[i]!=-1) return dp[i];
    unordered_map<int,int> mpp;
    int ans=INT_MAX;
    int count=0;
    for(int j=i;j<n;j++){
        mpp[nums[j]]++;
        if(mpp[nums[j]]==2){
            count+=2;
        }
        if(mpp[nums[j]]>2){
            count++;
        }
    ans=min(ans,k+solve(j+1,nums,k,dp)+count);
        
    }
return dp[i]=ans;
}
    int minCost(vector<int>& nums, int k) {
         n=nums.size();
         vector<int> dp(n + 1, -1);
        return solve(0,nums,k,dp);
    }
};