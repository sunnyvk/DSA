
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;

        int n = s.size();
        vector<int> dp(n, -1);

        return numDecoding(0, s, dp);
    }

    int numDecoding(int p, string& s, vector<int>& dp) {
        int n = s.size();

        if (p == n) return 1;
        if (s[p] == '0') return 0;

        if (dp[p] != -1) return dp[p];

        int res = numDecoding(p + 1, s, dp);

        if (p < n - 1 &&
            (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7'))) {
            res += numDecoding(p + 2, s, dp);
        }

        return dp[p] = res;
    }
};
