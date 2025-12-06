class Solution {
    int MOD=1e9+7;
    // int solve(int n,int absence,int consecutive_late){
    //     if(n==0) return 1;
    //     if(absence > 1 || consecutive_late > 2) return 0;
    //     int A=solve(n-1,absence+1,0);
    //     int L=solve(n-1,absence,consecutive_late+1);
    //     int P=solve(n-1,absence,0);
    //     return A+L+P;
    // }
public:
    int checkRecord(int n) {
        //  return   solve(n,0,0);
       vector<vector<vector<int>>> dp(n + 1,
                               vector<vector<int>> (2, vector<int>(3, -1)));
        for (int absence = 0; absence <= 1; absence++) {
            for (int consecutive_late = 0; consecutive_late <= 2;
                 consecutive_late++) {
                dp[0][absence][consecutive_late] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int absence = 0; absence <= 1; absence++) {
                for (int consecutive_late = 0; consecutive_late <= 2;
                     consecutive_late++) {
                        long long result=0;
                    result = (absence + 1 <= 1 ? dp[i-1][absence + 1][0] : 0);
                    result += (consecutive_late + 1 <= 2
                                ? dp[i-1][absence][consecutive_late + 1]
                                : 0);
                    result+= dp[i-1][absence][0];
                   
                    dp[i][absence][consecutive_late] = result%MOD;
                }
            }
        }
        return dp[n][0][0];
    }
};