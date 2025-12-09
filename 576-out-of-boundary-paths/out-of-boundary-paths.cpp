class Solution {
public:
    int M;
    int N;
    int MOD = 1e9 + 7;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m;
        N = n;
        vector<vector<int>> dp(
            M , vector<int>(N ,  0));
        dp[startRow][startColumn]=1;
        int result=0;
        for (int k = 1; k <= maxMove; k++) {
            vector<vector<int>> temp(M,vector<int> (N,0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (vector<int> dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x < 0 || x >= M || y < 0 || y >= N) {
                            result = (dp[i][j] + result) % MOD;
                        } else {
                            temp[x][y] = (temp[x][y] + dp[i][j]) % MOD;
                        }
                    }
                }
            }
            dp=temp;
        }
            return result;
        }
    };