class Solution {
public:
    int maxDistinct(string s) {
        vector<int> res(26,0);
        int count=0;
        for(int i=0;i<s.length();i++){
            if(res[s[i]-'a']==0){
                res[s[i]-'a']++;
                count++;
            }
        }
        return count;
    }
};