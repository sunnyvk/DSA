class Solution {
public:
    int n;
    vector<int> segMin, segMax, lazy;

    // Build segment tree
    void build(int i, int l, int r, vector<int>& v) {
        if (l == r) {
            segMin[i] = segMax[i] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*i+1, l, mid, v);
        build(2*i+2, mid+1, r, v);
        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    void pushDown(int i, int l, int r) {
        if (lazy[i] == 0) return;

        segMin[i] += lazy[i];
        segMax[i] += lazy[i];

        if (l != r) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }

    // Range add update
    void updateRange(int qs, int qe, int i, int l, int r, int val) {
        pushDown(i, l, r);

        if (r < qs || l > qe) return;

        if (l >= qs && r <= qe) {
            lazy[i] += val;
            pushDown(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        updateRange(qs, qe, 2*i+1, l, mid, val);
        updateRange(qs, qe, 2*i+2, mid+1, r, val);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    // Find rightmost index where value == 0
    int findRightMostZero(int i, int l, int r) {
        pushDown(i, l, r);

        if (segMin[i] > 0 || segMax[i] < 0)
            return -1;

        if (l == r)
            return l;

        int mid = (l + r) / 2;
        int right = findRightMostZero(2*i+2, mid+1, r);
        if (right != -1) return right;

        return findRightMostZero(2*i+1, l, mid);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();

        // next occurrence
        unordered_map<int,int> mp;
        vector<int> nextPos(n, n);
        for (int i = n-1; i >= 0; i--) {
            if (mp.count(nums[i])) nextPos[i] = mp[nums[i]];
            mp[nums[i]] = i;
        }

        // prefix sum (odd +1, even -1, unique only)
        vector<int> prefix(n, 0);
        unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            if (i > 0) prefix[i] = prefix[i-1];
            if (seen.count(nums[i])) continue;

            prefix[i] += (nums[i] % 2 == 0 ? -1 : 1);
            seen.insert(nums[i]);
        }

        // init segment tree
        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(0, 0, n-1, prefix);

        int ans = findRightMostZero(0, 0, n-1) + 1;

        for (int i = 1; i < n; i++) {
            int r = nextPos[i-1] - 1;
            int val = (nums[i-1] % 2 == 0 ? 1 : -1);

            updateRange(i, r, 0, 0, n-1, val);

            int idx = findRightMostZero(0, 0, n-1);
            if (idx != -1)
                ans = max(ans, idx - i + 1);
        }

        return ans;
    }
};
