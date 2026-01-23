class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int> mpp;
        int m=words[0].size();
        for(auto x:words){
            string s="";
            for(int i=1;i<m;i++){
                int diff=x[i]-x[i-1];
                if(diff<0) {diff+=26;}
                char c=(char)(diff+'a');
                s+=c;
            }
            mpp[s]++;
        }
        long long ans=0;
        for(auto it:mpp){
            long long fq = (long long)it.second;
            ans+=((fq)*(fq-1))/2;
        }
        return ans;
    }
};