class Solution {
public:
    int n, K;
    vector<int> prefix;
    vector<vector<int>> dp;

    int rangeSum(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }

    int solve(int i, int j) {
        if (i == j) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        // try all valid split points
        for (int mid = i; mid < j; mid += (K - 1)) {
            ans = min(ans,
                      solve(i, mid) + solve(mid + 1, j));
        }

        // if this segment can be merged into ONE pile
        if ((j - i) % (K - 1) == 0) {
            ans += rangeSum(i, j);
        }

        return dp[i][j] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        n = stones.size();
        K = k;

        if ((n - 1) % (k - 1) != 0)
            return -1;

        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};

