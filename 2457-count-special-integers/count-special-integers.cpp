class Solution {
public:
int dp[11][2][2][1024];
string s;
    int solve(int idx,bool tight,bool started,int mask){
        if(idx==s.size()){
            return started?1:0;
          }
    
    if(dp[idx][tight][started][mask]!=-1){
        return dp[idx][tight][started][mask];
    }
    int res=0;
    int limit=tight?(s[idx]-'0'):9;
    for(int digit=0;digit<=limit;digit++){
        if(started && (mask & (1<<digit))){
            continue;
        }
        bool new_started=started || (digit>0);
        bool new_tight=tight && (digit==limit);
        int new_mask=new_started? (mask | (1<<digit)):mask;
        res+=solve(idx+1,new_tight,new_started,new_mask);
    }
    return dp[idx][tight][started][mask]=res;
}
    int countSpecialNumbers(int n) {
        s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,true,false,0);
    }
};