class Solution {
 
public:
    int deleteAndEarn(vector<int>& nums) {
         int maxVal = 0;
        for (int x : nums) maxVal = max(maxVal, x);

        vector<int> points(maxVal + 1, 0);
        for (int x : nums) points[x] += x;
         vector<int> dp(maxVal + 1, 0);
        dp[0]=0;
        dp[1]=points[1];
        for(int i = 2; i <= maxVal; i++){
            int take = points[i] + dp[i - 2];
            int nottake = dp[i - 1];
            dp[i] = max(take, nottake);
        }

        return dp[maxVal];
    }
};