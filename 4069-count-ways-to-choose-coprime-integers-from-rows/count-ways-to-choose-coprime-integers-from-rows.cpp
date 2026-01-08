const int MOD=1e9+7;
class Solution {
public:
int recur(int idx,int g,vector<vector<int>>& mat,vector<vector<int>>& dp){
    int m=mat.size();
    if(idx==m){
        if(g==1) return 1;
        else return 0;
    }
    if(dp[idx][g]!=-1) return dp[idx][g];
    long long res=0;
    for(int i=0;i<mat[idx].size();i++){
        int value=mat[idx][i];
        int newg;
        if(idx==0) newg=value;
        else newg=__gcd(g,value);
        res=(res+recur(idx+1,newg,mat,dp))%MOD;
    }
    dp[idx][g]=res;
    return res;
}
    int countCoprime(vector<vector<int>>& mat) {
        int m=mat.size();
        vector<vector<int>> dp(m,vector<int> (151,-1));
        return recur(0,0,mat,dp);
    }
};