class Solution {
public:
    // dp[pos][tight][startZero][sumOdd][sumEven]
    long long dp[17][2][2][150][150];
    string s;
    long long solve(long long num) {
        if (num < 0)
            return 0;
        s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return helper(0, 1, 1, 0, 0);
    }
    long long helper(int idx, int tight, int startZero, int sumOdd,
                     int sumEven) {
        if (idx == s.size()) {
            return (sumOdd == sumEven);
        }
        if (dp[idx][tight][startZero][sumOdd][sumEven] != -1)
            return dp[idx][tight][startZero][sumOdd][sumEven];
        long long res = 0;
        int ub = tight ? (s[idx] - '0') : 9;
        for (int digit = 0; digit <= ub; digit++) {
            if (digit == 0 && startZero) {
                res +=
                    helper(idx + 1, tight && (digit == ub), 1, sumOdd, sumEven);
            } else {
                if (idx % 2 == 0) {
                    res += helper(idx + 1, tight && (digit == ub), 0, sumOdd,
                                  sumEven + digit);
                } else {
                    res += helper(idx + 1, tight && (digit == ub), 0,
                                  sumOdd + digit, sumEven);
                }
            }
        }
        return dp[idx][tight][startZero][sumOdd][sumEven] = res;
    }

    long long countBalanced(long long low, long long high) {
        return solve(high) - solve(low - 1);
    }
};