// class Solution {
// public:
//  bool isPalindrome(string s,int start,int end){
//     while(start<end){
//        if(s[start]!=s[end]){
//         return false;
//        }
//        start++;
//        end--;
//     }
//     return true;
//  }
//     string longestPalindrome(string s) {
//         if(s.length()<1) return "";
//         int n=s.length();
//         string longest="";
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 if(isPalindrome(s,i,j) && (j-i+1)>longest.length()){
//                     longest=s.substr(i,j-i+1);
//                 }
//             }
//         }
//         return longest;
//     }
// };

class Solution {
public:
 int expandAroundCenter(string s,int left,int right){
    while(left>=0 && right<s.length() && s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
 }
    string longestPalindrome(string s) {
            if(s.empty()) return "";
            int start=0;
            int end=0;
            for(int i=0;i<s.length();i++){
                int odd=expandAroundCenter(s,i,i);
                int even=expandAroundCenter(s,i,i+1);
                int max_len=max(odd,even);
                if(max_len>end-start){
                     start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
                }
            }

        return s.substr(start, end - start + 1);
    }
};