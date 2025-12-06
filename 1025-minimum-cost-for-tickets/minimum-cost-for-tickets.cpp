class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; index--) {
            int cost_1 = costs[0] + dp[index + 1];
            int max_day = days[index] + 7;
            int j = index;
            while (j < n && days[j] < max_day) {
                j++;
            }
            int cost_7 = costs[1] + dp[j];

            max_day = days[index] + 30;
            j = index;
            while (j < n && days[j] < max_day) {
                j++;
            }
            int cost_30 = costs[2] + dp[j];
            dp[index] = min({cost_1, cost_7, cost_30});
        }
        return dp[0];
    }
};