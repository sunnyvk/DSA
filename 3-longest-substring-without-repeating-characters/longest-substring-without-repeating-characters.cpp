class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        vector<int> mpp(256,-1);
        int l=0,r=0,maxLen=0;
        while(r<n){
            if(mpp[s[r]]!=-1){
                if(mpp[s[r]]>=l){
                    l=mpp[s[r]]+1;
                }
            }
          int  len=r-l+1;
            maxLen=max(len,maxLen);
            mpp[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};