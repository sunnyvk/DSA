class Solution {
public:
    string reorganizeString(string s) {
        
        int hash[26] = {0};

        // Count frequency of each character
        for (int i = 0; i < s.length(); i++) {
            hash[s[i] - 'a']++;
        }

        // Find character with maximum frequency
        int maxFreq = 0;
        int letter = 0;

        for (int i = 0; i < 26; i++) {
            if (hash[i] > maxFreq) {
                maxFreq = hash[i];
                letter = i;
            }
        }

        // If maximum frequency is too large,
        // it is impossible to reorganize
        if (maxFreq > (s.length() + 1) / 2) {
            return "";
        }

        string res(s.length(), ' ');

        int idx = 0;

        // Place the most frequent character first
        while (hash[letter] > 0) {
            res[idx] = char(letter + 'a');

            idx += 2;
            hash[letter]--;
        }

        // Place remaining characters
        for (int i = 0; i < 26; i++) {

            while (hash[i] > 0) {

                // Move to odd positions
                if (idx >= res.length()) {
                    idx = 1;
                }

                res[idx] = char(i + 'a');

                idx += 2;
                hash[i]--;
            }
        }

        return res;
    }
};