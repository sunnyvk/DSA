class Solution {
public:
    bool dfs(int side, int idx, int currSum,
             vector<int>& matchsticks, vector<bool>& used, int target) {

        // If 3 sides are completed, the 4th is automatically correct
        if (side == 3) return true;

        // Current side completed → move to next side
        if (currSum == target) {
            return dfs(side + 1, 0, 0, matchsticks, used, target);
        }

        for (int i = idx; i < matchsticks.size(); i++) {
            if (used[i]) continue;
            if (currSum + matchsticks[i] > target) continue;

            used[i] = true;
            if (dfs(side, i + 1, currSum + matchsticks[i],
                    matchsticks, used, target))
                return true;
            used[i] = false;

            // pruning: if first stick fails, no need to try others at same level
            if (currSum == 0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;

        int target = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<bool> used(matchsticks.size(), false);
        return dfs(0, 0, 0, matchsticks, used, target);
    }
};
