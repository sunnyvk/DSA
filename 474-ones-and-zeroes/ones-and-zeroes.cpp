class Solution {
    // int solve(int i, int m, int n, vector<pair<int, int>>&
    // count,vector<vector<vector<int>>> &dp) {
    //     if (i < 0 || (m==0 && n==0))
    //         return 0;
    //     int take = 0;
    //     if(dp[i][m][n]!=-1) return dp[i][m][n];
    //     if (count[i].first <= m && count[i].second <= n) {
    //          take = 1 + solve(i - 1, m - count[i].first, n - count[i].second,
    //                              count,dp);
    //     }
    //     int skip = solve(i - 1, m, n, count,dp);
    //     return dp[i][m][n]=max(take, skip);
    // }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<pair<int, int>> count(N);
        vector<vector<vector<int>>> dp(
            N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 0; i < N; i++) {
            int countofzeroes = 0;
            int countofones = 0;
            for (char ch : strs[i]) {
                if (ch == '0') {
                    countofzeroes++;
                } else {
                    countofones++;
                }
            }

            count[i] = {countofzeroes, countofones};
        }
        for (int i = 1; i <= N; i++) {
               int zeroes = count[i-1].first;
                int ones = count[i-1].second;
            for (int j = 0; j <= m; j++) {
             
                for (int k = 0; k <= n; k++) {
                    int take = 0;
                    if (zeroes <= j && ones <= k) {
                        take = 1 + dp[i - 1][j - zeroes][k - ones];
                    }
                    int skip = dp[i - 1][j][k];
                    dp[i][j][k] = max(take, skip);
                }
            }
        }

        return dp[N][m][n];
    }
};
