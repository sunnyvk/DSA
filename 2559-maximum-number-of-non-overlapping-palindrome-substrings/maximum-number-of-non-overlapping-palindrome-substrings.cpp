class Solution {
public:
 vector<int> dp;
bool isPal(string &s,int l,int r){
    while(l<r){
        if(s[l++]!=s[r--]) return false;
    }
    return true;
}
int solve(int i,string &s,int k){
    if(i>=s.size()) return 0;
    if (dp[i] != -1) return dp[i];
    int ans=solve(i+1,s,k);
    for(int j=i+k-1;j<s.size();j++){
        if(isPal(s,i,j)){
            ans=max(ans,1+solve(j+1,s,k));
            break;
        }
    }
    return dp[i]=ans;

}
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        dp.assign(s.size(), -1);
        return solve(0,s,k);
    }
};