class DisJointSet {
public:
    vector<int> rank, parent, size;

    DisJointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultP_u = findUPar(u);
        int ultP_v = findUPar(v);

        if (ultP_u == ultP_v) return;

        if (rank[ultP_u] < rank[ultP_v]) {
            parent[ultP_u] = ultP_v;
        }
        else if (rank[ultP_v] < rank[ultP_u]) {
            parent[ultP_v] = ultP_u;
        }
        else {
            parent[ultP_v] = ultP_u;
            rank[ultP_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ultP_u = findUPar(u);
        int ultP_v = findUPar(v);

        if (ultP_u == ultP_v) return;

        if (size[ultP_u] < size[ultP_v]) {
            parent[ultP_u] = ultP_v;
            size[ultP_v] += size[ultP_u];
        }
        else {
            parent[ultP_v] = ultP_u;
            size[ultP_u] += size[ultP_v];
        }
    }
};


class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {

        // Already have k components
        if (k == n)
            return 0;

        // Process cheapest edges first
        sort(edges.begin(), edges.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        DisJointSet ds(n);

        int components = n;

        for (auto &it : edges) {

            int u = it[0];
            int v = it[1];
            int weight = it[2];

            // Only useful if they belong to different components
            if (ds.findUPar(u) != ds.findUPar(v)) {

                ds.unionBySize(u, v);

                components--;

                // We reached exactly k components
                if (components == k) {
                    return weight;
                }
            }
        }

        return 0;
    }
};