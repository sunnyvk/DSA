class Solution {

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_index = ind - 1; prev_index >= -1; prev_index--) {
                int len = 0 + dp[ind + 1][prev_index+1];
                if (prev_index == -1 || pairs[ind][0] > pairs[prev_index][1]) {
                    len = max(len, 1 + dp[ind + 1][ind+1]);
                }
                dp[ind][prev_index + 1] = len;
            }
        }
        return dp[0][-1 + 1];
    }
};