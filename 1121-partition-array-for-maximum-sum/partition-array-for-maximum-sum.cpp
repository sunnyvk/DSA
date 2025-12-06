class Solution {
    // int solve(int ind,vector<int>& arr,int k){
    //     int n=arr.size();
    //     if(ind==n) return 0;
    //     int len=0,maxi=INT_MIN,maxAs=INT_MIN;
    //     for(int j=ind;j<min(n,ind+k);j++){
    //         len++;
    //         maxi=max(maxi,arr[j]);
    //        int sum=(len*maxi)+solve(j+1,arr,k);
    //          maxAs=max(sum,maxAs);
    //     }
    //     return maxAs;
    // }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int len = 0, maxi = INT_MIN, maxAs = INT_MIN;
            for (int j = i; j < min(n, i + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len * maxi) + dp[j + 1];
                maxAs = max(sum, maxAs);
            }
            dp[i] = maxAs;
        }
        return dp[0];
        // return solve(0,arr,k);
    }
};