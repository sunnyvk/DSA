class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;
        for (auto it : arr1) {
            string s = to_string(it);
            string pre = "";
            for (char ch : s) {
                pre += ch;
                mp[pre]++;
            }
        }
        int maxLength=0;
        for (auto it : arr2) {
            string s = to_string(it);
            string pre = "";
            for (char ch : s) {
                pre+=ch;
                if (mp.find(pre) != mp.end()) {
                    maxLength=max(maxLength,(int)pre.length());
                }
            }
        }
        return maxLength;
    }
};