class Solution {
public:
  int dp[101][101][102];
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
       
        memset(dp, 0, sizeof(dp));

        // length = size of subarray
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                for (int k = 0; k <= n; k++) {

                    // Option 1: remove boxes[l] now
                    dp[l][r][k] = (k + 1) * (k + 1);
                    if (l + 1 <= r)
                        dp[l][r][k] += dp[l + 1][r][0];

                    // Option 2: merge with same color later
                    for (int i = l + 1; i <= r; i++) {
                        if (boxes[i] == boxes[l]) {
                            dp[l][r][k] = max(
                                dp[l][r][k],
                                dp[l + 1][i - 1][0] + dp[i][r][k + 1]
                            );
                        }
                    }
                }
            }
        }

        return dp[0][n - 1][0];
    }
};

