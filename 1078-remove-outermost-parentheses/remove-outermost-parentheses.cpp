class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balanced = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (balanced > 0) {
                    result += s[i];
                }
                balanced++;
            } else {
                balanced--;
                if (balanced > 0) {
                    result += s[i];
                }
            }
        }
                 return result;
    }
};