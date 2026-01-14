class Solution {
public:
 vector<vector<vector<int>>> dp;
int solve(vector<int>& nums, int k,int ind,int op1,int op2){
    if(ind==nums.size()) return 0;
    if (dp[ind][op1][op2] != -1)
            return dp[ind][op1][op2];
    int ans=INT_MAX;
    if(op1!=0){
        int sumOp1=(int) ceil(nums[ind]/2.0)+solve(nums,k,ind+1,op1-1,op2);
        ans=min(ans,sumOp1);
    }
    if(op2!=0 && nums[ind]>=k){
          int sumOp2=(nums[ind]-k)+solve(nums,k,ind+1,op1,op2-1);
        ans=min(ans,sumOp2);
    }
    if(op1!=0 && op2!=0){
        int afterOp1=(int)ceil(nums[ind]/2.0);
        if(afterOp1>=k){
            int sumOp1Op2=(afterOp1-k)+solve(nums,k,ind+1,op1-1,op2-1);
            ans=min(ans,sumOp1Op2);
        }
        if(nums[ind]>=k){
              int sumOp2Op1=(int) ceil((nums[ind]-k)/2.0)+solve(nums,k,ind+1,op1-1,op2-1);
            ans=min(ans,sumOp2Op1);
        }
    }
    int sumNoOp=nums[ind]+solve(nums,k,ind+1,op1,op2);
    ans=min(ans,sumNoOp);

    return dp[ind][op1][op2]=ans;
}
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        dp.assign(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
       return solve(nums,k,0,op1,op2);
    }
};