class Solution {
public:
    vector<int> seg, lazy;

    /* ================= BUILD ================= */

    void build(int i, int l, int r) {
        if (l == r) {
            seg[i] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(2*i + 1, l, m);
        build(2*i + 2, m + 1, r);
        seg[i] = 0;
    }

    /* ================= PUSH ================= */

    void push(int i) {
        if (lazy[i] != 0) {
            seg[2*i + 1] = max(seg[2*i + 1], lazy[i]);
            seg[2*i + 2] = max(seg[2*i + 2], lazy[i]);

            lazy[2*i + 1] = max(lazy[2*i + 1], lazy[i]);
            lazy[2*i + 2] = max(lazy[2*i + 2], lazy[i]);

            lazy[i] = 0;
        }
    }

    /* ================= QUERY ================= */

    int querySegmentTree(int i, int l, int r, int ql, int qr) {
        if (r < ql || l > qr)
            return 0;

        if (l >= ql && r <= qr)
            return seg[i];

        push(i);

        int m = (l + r) / 2;
        return max(
            querySegmentTree(2*i + 1, l, m, ql, qr),
            querySegmentTree(2*i + 2, m + 1, r, ql, qr)
        );
    }

    /* ================= UPDATE ================= */

    void updateRange(int i, int l, int r,
                     int ql, int qr, int val) {
        if (r < ql || l > qr)
            return;

        if (l >= ql && r <= qr) {
            seg[i] = max(seg[i], val);
            lazy[i] = max(lazy[i], val);
            return;
        }

        push(i);

        int m = (l + r) / 2;
        updateRange(2*i + 1, l, m, ql, qr, val);
        updateRange(2*i + 2, m + 1, r, ql, qr, val);

        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }

    /* ================= MAIN ================= */

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();

        // Coordinate compression
        vector<int> coords;
        for (auto& p : positions) {
            coords.push_back(p[0]);
            coords.push_back(p[0] + p[1] - 1);
        }
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int m = coords.size();
        seg.assign(4 * m, 0);
        lazy.assign(4 * m, 0);

        build(0, 0, m - 1);

        vector<int> result;
        int globalMax = 0;

        for (auto& p : positions) {
            int left = p[0];
            int right = p[0] + p[1] - 1;

            int l = lower_bound(coords.begin(), coords.end(), left) - coords.begin();
            int r = lower_bound(coords.begin(), coords.end(), right) - coords.begin();

            int baseHeight = querySegmentTree(0, 0, m - 1, l, r);
            int newHeight = baseHeight + p[1];

            updateRange(0, 0, m - 1, l, r, newHeight);

            globalMax = max(globalMax, newHeight);
            result.push_back(globalMax);
        }

        return result;
    }
};
