class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long baseCost = 0;          // cost to match nums1 -> nums2 (index-wise)
        int v = nums2.back();            // value that must be inserted
        int extraCost = INT_MAX;         // minimum cost to insert v

        for (int i = 0; i < nums1.size(); i++) {
            int a = nums1[i];
            int b = nums2[i];

            // 1️⃣ Base cost: convert a -> b
            baseCost += abs(a - b);

            // 2️⃣ Check if v lies between a and b
            if (min(a, b) <= v && v <= max(a, b)) {
                // v can be inserted for free (only insertion operation cost = 1)
                extraCost = 1;
            } else {
                // otherwise, pay distance to reach v + insertion cost
                int costHere = 1 + min(abs(a - v), abs(b - v));
                extraCost = min(extraCost, costHere);
            }
        }

        return baseCost + extraCost;
    }
};
