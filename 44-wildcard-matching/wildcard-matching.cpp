class Solution {
    bool wildcardMatch(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(j == 0 && i > 0){
            for(int k=1;k<=i;k++){
                if(s1[k-1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //if character matches
        if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
            return dp[i][j] = wildcardMatch(i-1,j-1,s1,s2,dp);
        }
        if(s1[i-1] == '*'){
            return dp[i][j] = (wildcardMatch(i-1,j,s1,s2,dp) | wildcardMatch(i,j-1,s1,s2,dp));
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        //1-based indexing
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,-false));
        //tabulation method
        dp[0][0] = true;
        for(int j=1;j<=m;j++){
            dp[0][j] = false;
        }
        for(int i=1;i<=n;i++){
            int flag=true;
            for(int k =1;k<=i;k++){
                if(p[k-1]!='*'){
                    flag=false;
                      dp[i][0]=false;
                }
            }
            dp[i][0] = flag;
        }

        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(p[i-1] == s[j-1] || p[i-1] == '?'){
                     dp[i][j] = dp[i-1][j-1];
            }
                else if(p[i-1] == '*'){
                     dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
            }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
        //return wildcardMatch(n,m,p,s,dp);
    }
};