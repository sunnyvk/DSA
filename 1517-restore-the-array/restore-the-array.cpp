class Solution {
    int MOD=1e9+7;
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int start = n - 1; start >= 0; start--) {
            if (s[start] == '0') {
                dp[start] = 0;
                continue;
            }
            long long num = 0;
            for (int end = start; end < n; end++) {
                num = num * 10 + (s[end] - '0');

                if (num > k)
                    break;

                dp[start] = (dp[start] + dp[end + 1]) % MOD;
            }
        }
        return dp[0];
    }
};