
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<pair<int, int>> ans;

        sort(nums1.begin(), nums1.end());

        for (int i = 0; i < n; i++) {
            ans.push_back({nums2[i], i});
        }

        vector<int> result(n, 0);
        sort(ans.begin(), ans.end());

        int leftA = 0, rightA = n - 1;
        int leftB = 0, rightB = n - 1;

        while (leftA <= rightA) {
            if (nums1[leftA] > ans[leftB].first) {
                result[ans[leftB].second] = nums1[leftA];
                leftA++;
                leftB++;
            } else {
                result[ans[rightB].second] = nums1[leftA];
                leftA++;
                rightB--;
            }
        }

        return result;
    }
};
