class Solution {
public:
long long MOD=1e9+7;
 vector<vector<int>> dp;

long long recur(int n,bool is_filled){
    if(n==1) return 1;
     if (dp[n][is_filled] != -1)
            return dp[n][is_filled];
    if(is_filled){
        return dp[n][1]=recur(n-1,!is_filled);
    }else{
        return dp[n][0]=(recur(n-1,!is_filled)+recur(n-1,is_filled))%MOD;
    }
}
    int countHousePlacements(int n) {
          dp.resize(n + 1, vector<int> (2, -1));
         long long ways_of_one_side=(recur(n,0)+recur(n,1))%MOD;
           
        return (ways_of_one_side * ways_of_one_side) % MOD;
    }
};