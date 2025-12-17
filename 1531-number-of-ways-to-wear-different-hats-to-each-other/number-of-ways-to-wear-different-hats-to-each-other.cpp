class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    vector<vector<int>> hatToPeople;
    int dp[41][1 << 10];

    int solve(int hat, int mask) {
        if (mask == (1 << n) - 1) return 1;
        if (hat > 40) return 0;

        int &res = dp[hat][mask];
        if (res != -1) return res;

        long long ways = 0;

        // Option 1: skip this hat
        ways = solve(hat + 1, mask);

        // Option 2: assign this hat
        for (int person : hatToPeople[hat]) {
            if ((mask & (1 << person)) == 0) {
                ways += solve(hat + 1, mask | (1 << person));
            }
        }

        return res = ways % MOD;
    }

    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        hatToPeople.assign(41, {});

        // Build hat → people mapping
        for (int person = 0; person < n; person++) {
            for (int hat : hats[person]) {
                hatToPeople[hat].push_back(person);
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(1, 0);
    }
};
