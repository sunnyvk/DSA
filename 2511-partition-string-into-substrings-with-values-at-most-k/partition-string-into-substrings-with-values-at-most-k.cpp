class Solution {
public:
    int minimumPartition(string s, int k) {
        long long res = 0, n = 0;
        for (int i = 0; i < s.length(); i++) {
             n = n * 10 + s[i] - '0';
            if (n > k) {
                res++;
                n = s[i] - '0';
            }
            if (n > k) {
                return -1;
            }
        }
        return res+1;
    }

}
;