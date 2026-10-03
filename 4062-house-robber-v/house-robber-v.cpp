class Solution {
public:
int n;
 long long dp[100001];
long long solve(int ind,vector<int>& nums,vector<int>& colors){
    if(ind>=n) return 0;
      if(dp[ind]!=-1) return dp[ind]; 
    if(ind==n-1) return nums[ind];
    long long val1=0,val2=0;
    if(colors[ind]==colors[ind+1]){
        val1=nums[ind]+solve(ind+2,nums,colors);
    }else{
        val1=nums[ind]+solve(ind+1,nums,colors);
    }
    val2=solve(ind+1,nums,colors);
    return dp[ind]=max(val1,val2);
}
    long long rob(vector<int>& nums, vector<int>& colors) {
            memset(dp,-1,sizeof(dp));
        n=nums.size();
        return solve(0,nums,colors);
    }
};