class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
       int next1 = 1;  
        int next2 = 0;  
        int curr = 0;
        for (int i = n - 1; i >= 0; i--) {
                  if (s[i] == '0'){
                    curr = 0; 
                      next2 = next1;
                next1 = curr; 
                    continue;
                  }
           curr= next1;
             if (i + 1 < n) {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                    curr += next2;
            }
            next2=next1;
            next1 = curr;
        }
        return curr;
    }
};