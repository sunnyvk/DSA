class Solution {
public:
long long MOD=1e9+7;
int calc(int base,int power){
    long long ans=1;
    while(power>0){
        if(power%2==0){
            base=(base*1LL*base)%MOD;
            power/=2;
        }else{
            ans=(ans*base)%MOD;
            power--;
        }
    }
    return (int)ans;
}
    int countWays(vector<vector<int>>& ranges) {
        int n=ranges.size();
        sort(ranges.begin(),ranges.end());
        int prevstart=ranges[0][0],prevend=ranges[0][1];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(ranges[i][0]<=prevend){
                prevend=max(prevend,ranges[i][1]);
            }else{
                prevstart=ranges[i][0];
                prevend=ranges[i][1];
                cnt++;
            }
        }
        return calc(2,cnt);
    }
};