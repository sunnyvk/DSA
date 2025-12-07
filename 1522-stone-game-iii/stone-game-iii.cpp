class Solution {
    // int solve(int i, vector<int>& stoneValue) {
    //     int n = stoneValue.size();
    //     if (i == n)
    //         return 0;
    //     int result = INT_MIN;
    //     result = max(result, stoneValue[i] - solve(i + 1, stoneValue));
    //     if (i + 1 < n)
    //         result = max(result, stoneValue[i] + stoneValue[i + 1] -
    //                                  solve(i + 2, stoneValue));
    //     if (i + 2 < n)
    //         result =
    //             max(result, stoneValue[i] + stoneValue[i + 1] +
    //                             stoneValue[i + 2] - solve(i + 3, stoneValue));
    //     return result;
    // }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int result = INT_MIN;
            result = max(result, stoneValue[i] - dp[i + 1]);
            if (i + 1 < n)
                result = max(result, stoneValue[i] + stoneValue[i + 1] -
                                        dp[i + 2]);
            if (i + 2 < n)
                result = max(result, stoneValue[i] + stoneValue[i + 1] +
                                         stoneValue[i + 2] -
                                         dp[i + 3]);
                                         dp[i]=result;
        }
        int diff = dp[0];
        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        }
        return "Tie";
    }
};