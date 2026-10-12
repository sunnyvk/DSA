class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26,0);
       
        vector<string> s;
        int n=words1.size();
        for(auto st:words2){
             vector<int> tempFreq(26,0);
            for(char ch:st){
                tempFreq[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                maxFreq[i]=max(maxFreq[i],tempFreq[i]);
            }
        }
         vector<string> ans;
          for(auto st:words1){
             vector<int> tempFreq(26,0);
            for(char ch:st){
                tempFreq[ch-'a']++;
            }
            bool universe=true;
            for(int i=0;i<26;i++){
                   if (tempFreq[i] < maxFreq[i]) {
                    universe = false;
                    break;
                }
            }
            if(universe){
                ans.push_back(st);
            }
        }
        return ans;
    }
};