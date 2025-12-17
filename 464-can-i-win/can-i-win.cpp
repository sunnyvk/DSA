class Solution {
public:
int dp[1<<20];
bool solve(int M,int T,int K){
    if(T<=0) return 0;
    if(dp[K]!=-1) return dp[K];

    for(int i=0;i<M;i++){
    if (!(K & (1 << i))) {

                // 🔥 IMMEDIATE WIN CHECK
                if (T - (i + 1) <= 0)
                    return dp[K] = 1;

                // Otherwise try opponent
                if (!solve(M, T - (i + 1), K | (1 << i)))
                    return dp[K] = 1;
            }
    }
    return dp[K]=0;
}
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal==0) return 1;
        int total=maxChoosableInteger*(maxChoosableInteger+1)/2;
        if(total<desiredTotal) return 0;
        if(total==desiredTotal) return maxChoosableInteger%2;
        memset(dp,-1,sizeof dp);

        return solve(maxChoosableInteger,desiredTotal,0);
    }
};