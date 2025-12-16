class Solution {
public:
int dp[501][501];
    int solve(vector<int>& piles, int l, int r) {

        if (l > r)
            return 0;

        if (l == r)
            return piles[l];

        if(dp[l][r] != -1)
            return dp[l][r];

        int take_left =
            piles[l] + min(solve(piles, l + 2, r), solve(piles, l + 1, r - 1));

        int take_right =
            piles[r] + min(solve(piles, l, r - 2), solve(piles, l + 1, r - 1));

        return dp[l][r]=max(take_left, take_right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        int total = accumulate(begin(piles), end(piles), 0);

        int player1 = solve(piles, 0, n - 1);
        int player2 = total - player1;
        return player1 >= player2;
    }
};
