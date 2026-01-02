class Solution {
public:
    // input array
    vector<int> arr;

    // segment tree node
    struct Node {
        long long total;   // total stable subarrays
        int pref;          // non-decreasing prefix length
        int suff;          // non-decreasing suffix length
        int len;           // segment length
        bool full;         // entire segment non-decreasing

        Node(long long t=0, int p=0, int s=0, int l=0, bool f=false)
            : total(t), pref(p), suff(s), len(l), full(f) {}
    };

    // segment tree
    vector<Node> segmentTree;

    // merge two nodes
    Node mergeNode(const Node &L, const Node &R, int mid) {
        if (L.len == 0) return R;
        if (R.len == 0) return L;

        Node res;
        res.len = L.len + R.len;

        bool canJoin = (arr[mid] <= arr[mid + 1]);

        res.full = L.full && R.full && canJoin;

        res.pref = (L.full && canJoin) ? L.len + R.pref : L.pref;
        res.suff = (R.full && canJoin) ? R.len + L.suff : R.suff;

        res.total = L.total + R.total;
        if (canJoin) {
            res.total += 1LL * L.suff * R.pref;
        }

        return res;
    }

    // build segment tree
    void buildSegmentTree(int i, int l, int r) {
        if (l == r) {
            // single element
            segmentTree[i] = Node(1, 1, 1, 1, true);
            return;
        }

        int mid = (l + r) / 2;
        buildSegmentTree(2*i + 1, l, mid);
        buildSegmentTree(2*i + 2, mid + 1, r);

        segmentTree[i] = mergeNode(
            segmentTree[2*i + 1],
            segmentTree[2*i + 2],
            mid
        );
    }

    // query segment tree
    Node querySegmentTree(int ql, int qr, int i, int l, int r) {
        if (r < ql || l > qr) {
            return Node(); // empty node
        }

        if (ql <= l && r <= qr) {
            return segmentTree[i];
        }

        int mid = (l + r) / 2;

        return mergeNode(
            querySegmentTree(ql, qr, 2*i + 1, l, mid),
            querySegmentTree(ql, qr, 2*i + 2, mid + 1, r),
            mid
        );
    }

    vector<long long> countStableSubarrays(
        vector<int>& nums,
        vector<vector<int>>& queries
    ) {
        arr = nums;
        int n = arr.size();

        segmentTree.assign(4 * n, Node());

        buildSegmentTree(0, 0, n - 1);

        vector<long long> ans;
        for (auto &q : queries) {
            ans.push_back(
                querySegmentTree(q[0], q[1], 0, 0, n - 1).total
            );
        }

        return ans;
    }
};
