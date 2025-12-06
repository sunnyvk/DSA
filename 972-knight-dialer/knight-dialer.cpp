class Solution {
    int MOD = 1e9 + 7;
    vector<vector<int>> adj = {{4, 6}, {6, 8},    {7, 9}, {4, 8}, {3, 9, 0},
                               {},     {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

public:
    int knightDialer(int n) {
        int result = 0;
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
        for (int cell = 0; cell <= 9; cell++) {
            dp[0][cell] = 1;
        }
        for (int i = 1; i <= n - 1; i++) {
            for (int cell = 0; cell <= 9; cell++) {
                int ans = 0;
                for (int& nextcell : adj[cell]) {
                    ans =(ans+ dp[i - 1][nextcell]) % MOD;
                }
                dp[i][cell] = ans;
            }
        }
        for (int cell = 0; cell <= 9; cell++) {
            result =(result+ dp[n - 1][cell]) % MOD;
        }
        return result;
    }
};