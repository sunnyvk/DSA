
class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
        vector<int> result;

        if (t.size() > s.size())
            return result;

        unordered_map<char, int> mp;

        for (char c : t) {
            mp[c]++;
        }

        int counter = mp.size();
        int left = 0, right = 0;

        while (right < s.size()) {
            char c = s[right];

            if (mp.find(c) != mp.end()) {
                mp[c]--;

                if (mp[c] == 0)
                    counter--;
            }

            right++;

            while (counter == 0) {
                char temp = s[left];

                if (mp.find(temp) != mp.end()) {
                    mp[temp]++;

                    if (mp[temp] > 0)
                        counter++;
                }

                if (right - left == t.size()) {
                    result.push_back(left);
                }

                left++;
            }
        }

        return result;
    }
};
