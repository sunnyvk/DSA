class Solution {
public:
    int m, n;
    vector<vector<char>> seats;
    vector<vector<int>> dp;

    int solve(int row, int prevMask) {
        if (row == m) return 0;

        if (dp[row][prevMask] != -1)
            return dp[row][prevMask];

        int maxStudents = 0;

        // Try all masks for current row
        for (int mask = 0; mask < (1 << n); mask++) {

            bool valid = true;
            int count = 0;

            for (int col = 0; col < n; col++) {
                if (mask & (1 << col)) {

                    // broken seat
                    if (seats[row][col] == '#') {
                        valid = false;
                        break;
                    }

                    // left-right adjacency (same row)
                    if (col > 0 && (mask & (1 << (col - 1)))) {
                        valid = false;
                        break;
                    }

                    // diagonal conflict (previous row)
                    if ((col > 0 && (prevMask & (1 << (col - 1)))) ||
                        (col + 1 < n && (prevMask & (1 << (col + 1))))) {
                        valid = false;
                        break;
                    }

                    count++;
                }
            }

            if (valid) {
                maxStudents = max(
                    maxStudents,
                    count + solve(row + 1, mask)
                );
            }
        }

        return dp[row][prevMask] = maxStudents;
    }

    int maxStudents(vector<vector<char>>& seatsInput) {
        seats = seatsInput;
        m = seats.size();
        n = seats[0].size();

        dp.assign(m, vector<int>(1 << n, -1));

        return solve(0, 0);
    }
};

