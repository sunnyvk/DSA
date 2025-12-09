class Solution {
    int n;
  
    double solve(int i, vector<int>& nums,int k, vector<vector<double>> &dp) {
        if (i == n)
            return 0.0;
            if(k==0) return -1e15;
            if(dp[i][k]!=-1.0) return dp[i][k];
        double len = 0.0;
        double sum = 0.0;
        double maxAns = 0.0;
        for (int j = i; j <=n-k; j++) {
            len++;
            sum += nums[j];
            double avg = (sum / len) + solve(j + 1, nums,k-1,dp);
            maxAns = max(maxAns, avg);
        }
        return dp[i][k]=maxAns;
    }

public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<double>> dp(n+1,vector<double> (k+1,-1.0));
       return solve(0, nums,k,dp);
    }
};