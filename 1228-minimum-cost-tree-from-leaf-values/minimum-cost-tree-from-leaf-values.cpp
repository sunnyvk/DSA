class Solution {
public:
 int dp[41][41];

    int getMax(int l, int r, vector<int>& arr) {
        int mx = 0;
        for (int i = l; i <= r; i++)
            mx = max(mx, arr[i]);
        return mx;
    }
int solve(int i,int j,vector<int>& arr){
    if(i>=j) return 0;
     if (dp[i][j] != -1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
         int leftMax  = getMax(i, k, arr);
            int rightMax = getMax(k + 1, j, arr);

            int val = leftMax * rightMax
                    + solve(i, k, arr)
                    + solve(k + 1, j, arr);

            ans = min(ans, val);
    }
     return dp[i][j] = ans;
}
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        int n=arr.size();
        return solve(0,n-1,arr);
    }
};