class Solution {
public:
int MOD=1e9+7;
    int countOrders(int n) {
        if(n==1) return 1;
        long long result=1;
        for(int i=2;i<=n;i++){
           int spaces=(i-1)*2+1;
           int possibilities=spaces*(spaces+1)/2;
           result *=possibilities;
           result %=MOD;
        }
        return result;
    }
};