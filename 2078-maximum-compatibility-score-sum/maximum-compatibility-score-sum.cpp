class Solution {
public:
int used[9] = {}, ans = 0, m, n;
    void dfs(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int score) {
         if (i == n) {
            ans = max(ans, score);
            return;
        }
        for(int j=0;j<n;j++){
                if (used[j]) continue;
            used[j] = 1;
            int s = 0;
            for (int k = 0; k < m; ++k) s += students[i][k] == mentors[j][k]; 
            dfs(students, mentors, i + 1, score + s);
            used[j] = 0;
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
         n=students.size();
         m=students[0].size();
         dfs(students, mentors, 0, 0);
        return ans;
     
    }
};