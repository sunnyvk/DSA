class Solution {
public:
    using ll = long long;

    void updateSegmentTree(int i, int l, int r, int updateIndex, vector<ll>& segmentTree) {
        if (l == r) {
            segmentTree[i] += 1;   // increment frequency
            return;
        }

        int mid = l + (r - l) / 2;
        if (updateIndex <= mid)
            updateSegmentTree(2 * i + 1, l, mid, updateIndex, segmentTree);
        else
            updateSegmentTree(2 * i + 2, mid + 1, r, updateIndex, segmentTree);

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    ll querySegmentTree(int qs, int qe, int i, int l, int r, vector<ll>& segmentTree) {
        if (r < qs || l > qe)
            return 0;

        if (l >= qs && r <= qe)
            return segmentTree[i];

        int mid = l + (r - l) / 2;
        return querySegmentTree(qs, qe, 2 * i + 1, l, mid, segmentTree) +
               querySegmentTree(qs, qe, 2 * i + 2, mid + 1, r, segmentTree);
    }

    ll countMajoritySubarrays(vector<int>& A, int target) {
        int n = A.size();
        vector<ll> prefix(n + 1, 0);

        // prefix sum: +1 for target, -1 otherwise
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + (A[i] == target ? 1 : -1);

        // coordinate compression
        set<ll> s(prefix.begin(), prefix.end());
        unordered_map<ll, int> mp;
        int id = 0;
        for (ll x : s)
            mp[x] = id++;

        int m = id;
        vector<ll> segmentTree(4 * m, 0);

        ll result = 0;

        for (ll p : prefix) {
            int idx = mp[p];

            // count previous prefix sums < current
            if (idx > 0)
                result += querySegmentTree(0, idx - 1, 0, 0, m - 1, segmentTree);

            // add current prefix sum
            updateSegmentTree(0, 0, m - 1, idx, segmentTree);
        }

        return result;
    }
};
