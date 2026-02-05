class Solution {
public:
    const int MOD = 1e9 + 7;

    int numDecodings(string s) {
        int n = s.size();

        long long next2 = 1;  // dp[n] = 1 (empty string)
        long long next1 = ways1(s[n-1]); // dp[n-1]

        for (int i = n - 2; i >= 0; i--) {
            long long cur = (ways1(s[i]) * next1) % MOD;
            cur = (cur + ways2(s[i], s[i+1]) * next2) % MOD;

            next2 = next1;
            next1 = cur;
        }

        return (int)next1;
    }

private:
    // Ways to decode one character
    long long ways1(char c) {
        if (c == '0') return 0;
        if (c == '*') return 9;
        return 1;
    }

    // Ways to decode two characters together
    long long ways2(char c1, char c2) {
        if (c1 == '*' && c2 == '*') return 15;

        if (c1 == '*') {
            if (c2 >= '0' && c2 <= '6') return 2; // 10–16 or 20–26
            return 1; // 17–19
        }

        if (c2 == '*') {
            if (c1 == '1') return 9; // 11–19
            if (c1 == '2') return 6; // 21–26
            return 0;
        }

        int num = (c1 - '0') * 10 + (c2 - '0');
        return (num >= 10 && num <= 26) ? 1 : 0;
    }
};


