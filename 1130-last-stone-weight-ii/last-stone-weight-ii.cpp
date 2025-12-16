class Solution {
    int n;
    int totalSum;
    vector<vector<int>> dp;

    int solve(int i, int diff, vector<int>& stones) {
        if (i == n) {
            return abs(diff);
        }

        if (dp[i][diff + totalSum] != -1)
            return dp[i][diff + totalSum];

        int takeLeft = solve(i + 1, diff + stones[i], stones);
        int takeRight = solve(i + 1, diff - stones[i], stones);

        return dp[i][diff + totalSum] = min(takeLeft, takeRight);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        totalSum = 0;
        for (int x : stones) totalSum += x;

        dp.assign(n, vector<int>(2 * totalSum + 1, -1));

        return solve(0, 0, stones);
    }
};

