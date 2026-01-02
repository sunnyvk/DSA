class Solution {
public:
    struct Node {
        long long val, sum;
        int len;
        Node(long long v = 0, long long s = 0, int l = 0)
            : val(v), sum(s), len(l) {}
    };
    static const long long MOD = 1000000007;

    int n;
    string s;
    vector<Node> seg;
    vector<long long> p10;



    // merge two segment tree nodes
    Node merge(Node left, Node right) {
        if (left.len == 0) return right;
        if (right.len == 0) return left;

        long long newVal =
            (left.val * p10[right.len] % MOD + right.val) % MOD;
        long long newSum = (left.sum + right.sum) % MOD;

        return Node(newVal, newSum, left.len + right.len);
    }

    // build segment tree
    void buildSegmentTree(int i, int l, int r) {
        if (l == r) {
            int d = s[l] - '0';
            if (d == 0)
                seg[i] = Node();
            else
                seg[i] = Node(d, d, 1);
            return;
        }

        int mid = (l + r) / 2;
        buildSegmentTree(2 * i + 1, l, mid);
        buildSegmentTree(2 * i + 2, mid + 1, r);
        seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
    }

    // range query
    Node querySegmentTree(int ql, int qr, int i, int l, int r) {
        if (r < ql || l > qr) return Node();
        if (ql <= l && r <= qr) return seg[i];

        int mid = (l + r) / 2;
        return merge(
            querySegmentTree(ql, qr, 2 * i + 1, l, mid),
            querySegmentTree(ql, qr, 2 * i + 2, mid + 1, r)
        );
    }

    // main function
    vector<int> sumAndMultiply(string str, vector<vector<int>>& queries) {
        s = str;
        n = s.size();

        seg.assign(4 * n, Node());
        p10.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            p10[i] = (p10[i - 1] * 10) % MOD;

        buildSegmentTree(0, 0, n - 1);

        vector<int> ans;
        for (auto &q : queries) {
            Node res = querySegmentTree(q[0], q[1], 0, 0, n - 1);
            ans.push_back((res.val * res.sum) % MOD);
        }
        return ans;
    }
};
