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
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expandFromCenter(s, i, i, start, maxLen);

            // Even length palindrome
            expandFromCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandFromCenter(string &s, int left, int right, int &start, int &maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            left--;
            right++;
        }
    }
};
