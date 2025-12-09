class Solution {

    double solve(int query_row, int query_glass, int poured,
                 vector<vector<double>>& dp) {
        if (query_row < 0 || query_glass < 0 || query_row < query_glass)
            return 0.0;
        if (query_row == 0 && query_glass == 0)
            return poured;
            if(dp[query_row][query_glass]!=-1) return dp[query_row][query_glass];
        double left_up =
            (solve(query_row - 1, query_glass - 1, poured,dp) - 1) / 2.0;
        double right_up = (solve(query_row - 1, query_glass, poured,dp) - 1) / 2.0;
        if (left_up < 0)
            left_up = 0.0;
        if (right_up < 0)
            right_up = 0.0;
        return dp[query_row][query_glass]=left_up + right_up;
    }

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1,
                                  vector<double>(query_glass+1, -1));
        return min(1.0, solve(query_row, query_glass, poured, dp));
    }
};