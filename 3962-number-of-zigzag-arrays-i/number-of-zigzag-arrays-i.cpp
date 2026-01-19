class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD=1e9+7;
        vector<int> dp(r+1,1);
        for(int i=1;i<n;i++){
            vector<int> next_dp(r+1);
            if(i%2==1){
                long pre=0;
                for(int x=l;x<=r;x++){
                    next_dp[x]=(int)pre;
                    pre=(pre+dp[x])%MOD;
                }
            }else{
                long suff=0;
                for(int x=r;x>=l;x--){
                    next_dp[x]=(int)suff;
                    suff=(suff+dp[x])%MOD;
                }
            }
            dp=next_dp;
        }
        long count=0;
        for(int x=l;x<=r;x++){
            count=(count+dp[x])%MOD;
        }
        return (int)((count*2)%MOD);
    }
};