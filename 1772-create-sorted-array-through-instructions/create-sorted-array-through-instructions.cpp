class BIT {
    vector<int> bit;
public:
    BIT(int size) {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) { // Get sum in range [0..idx], 1-based indexing
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    int getSumRange(int left, int right) { // left, right inclusive, 1-based indexing
        return getSum(right) - getSum(left - 1);
    }
    void addValue(int idx, int val) { // 1-based indexing
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int max = *max_element(instructions.begin(), instructions.end()), MOD = 1000000007;
        BIT bit(max);
        int cost = 0;
        for (int x : instructions) {
            int left = bit.getSumRange(0, x - 1);  // Get count of all numbers strictly less than x
            int right = bit.getSumRange(x + 1, max);  // Get count of all numbers strictly greater than x
            cost = (cost + min(left, right)) % MOD;
            bit.addValue(x, 1);  // Increase count of number x by one
        }
        return cost;
    }
};