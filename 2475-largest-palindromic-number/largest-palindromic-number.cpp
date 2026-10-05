class Solution {
public:
    string largestPalindromic(string num) {
        string first="",second="",mid="";
        vector<int> count(10,0);
        for(auto it:num){
            count[it-'0']++;
        }
        for(int i=9;i>=0;i--){
            if(i==0 && first.empty()) continue;
            while(count[i]>1){
                first+=to_string(i);
                count[i]-=2;
            }
        }
        for(int i=9;i>=0;i--){
            if(count[i]>0){
                mid=to_string(i);
                break;
            }
        }
        second=first;
        reverse(second.begin(),second.end());
        string ans=first+mid+second;
        return ans.empty() ? "0" : ans;



    }
};