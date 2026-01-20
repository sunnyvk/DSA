class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        int mn = nums.size();
        for (auto &p : freq) {
            mn = min(mn, p.second);
        }

        // Try group sizes from largest to smallest
        for (int size = mn; size >= 1; --size) {
            int groups = groupify(freq, size);
            if (groups > 0) return groups;
        }

        return nums.size();
    }

private:
    int groupify(unordered_map<int, int>& freq, int size) {
        int groups = 0;
        int next = size + 1;

        for (auto &p : freq) {
            int value = p.second;

            int numGroups = value / next;
            int remaining = value % next;

            if (remaining == 0) {
                groups += numGroups;
            }
            else if (numGroups >= size - remaining) {
                // We can redistribute elements to make all groups valid
                groups += numGroups + 1;
            }
            else {
                // Impossible for this size
                return 0;
            }
        }
        return groups;
    }
};
