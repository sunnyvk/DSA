class Solution {
public:
    int ans = INT_MAX;
    void bfs(int src, vector<vector<int>> &adj, int n) {
        vector<int> distance(n, (1e9));
        vector<int> parent(n, -1);
        queue<int> q;
        distance[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (distance[it] == (int)(1e9)) {
                    distance[it] = 1 + distance[node];
                    parent[it] = node;
                    q.push(it);
                } else if (parent[node] != it && parent[it] != node) {
                    ans = min(ans, distance[it] + distance[node] + 1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
   vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            bfs(i, adj, n);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};