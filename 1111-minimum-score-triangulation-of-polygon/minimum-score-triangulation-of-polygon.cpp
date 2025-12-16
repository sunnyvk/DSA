class Solution {
public:
int dp[105][105];
int solve(int i,int j,vector<int>& values){
    if(j-i<2) return 0;
    
        if (dp[i][j] != -1)
            return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
         int cost=values[i]*values[j]*values[k]+solve(i,k,values)+solve(k,j,values);
         ans=min(ans,cost);
    }
    return dp[i][j]=ans;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
         memset(dp, -1, sizeof(dp));
       return solve(0,n-1,values);
    }
};