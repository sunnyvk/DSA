// class Solution {
// public:
//     int dp[2001];
//     int solve(int target, int curr_sum, vector<int>& nums){
//         if(target == curr_sum){
//             return 1;
//         }
//         if(target < curr_sum){
//             return 0;
//         }

//         if(dp[curr_sum] != -1){
//             return dp[curr_sum];
//         }

//         int cnt =0;
//         for(int i=0; i< nums.size(); i++){
//             cnt += solve(target, curr_sum + nums[i], nums );
//         }
//         return dp[curr_sum] =  cnt;
//     }
//     int combinationSum4(vector<int>& nums, int target) {
//         int curr_sum =0;
//         memset(dp,-1, sizeof(dp));
//         int cnt = solve(target, curr_sum, nums);
//         return cnt;
//     }
// };






class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] =1;

        for(int sum =1; sum <= target; sum++ ){
            for(int num: nums){
                if(num <= sum){
                    dp[sum] += dp[sum-num];
                }
            }
        }
        return dp[target];
    }
};
