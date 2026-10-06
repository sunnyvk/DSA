class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {

        long long total = 0;
        unordered_map<int, int> freq;

        for (int x : nums) {
            total += x;
            freq[x]++;
        }

        int ans = INT_MIN;

        for (int s : nums) {

            long long candidate = total - 2LL * s;

            if (freq.count(candidate)) {

                if (candidate == s) {
                    if (freq[s] >= 2)
                        ans = max(ans, (int)candidate);
                }
                else {
                    ans = max(ans, (int)candidate);
                }
            }
        }

        return ans;
    }
};