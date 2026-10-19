class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int> count(26, 0);
         int left=0,right=0,maxlen=0,maxfreq=0;
         while(right<s.length()){
                count[s[right]-'A']++;
                maxfreq=max(maxfreq,count[s[right]-'A']);
                while((right-left+1)-maxfreq>k){
                    count[s[left]-'A']--;
                    maxfreq=0;
                    for(int i=0;i<=25;i++){
                        maxfreq=max(maxfreq,count[i]);
                       
                    }
                     left=left+1;
                }
            if((right-left+1)-maxfreq<=k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
         }
         return maxlen;
    }
};