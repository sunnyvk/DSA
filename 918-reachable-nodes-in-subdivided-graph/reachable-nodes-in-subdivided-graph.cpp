class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        const int INF = 1e18;
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<int> distance(n, INF);
        distance[0] = 0;
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                if (dist + it.second + 1 < distance[it.first]) {
                    distance[it.first] = dist + it.second + 1;
                    pq.push({distance[it.first],it.first});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (distance[i] <= maxMoves) {
                ans++;
            }
        }
        for (auto it : edges) {
            int src = it[0], dest = it[1], between = it[2];
            int x = max(0, (maxMoves - distance[src]));
            int y = max(0, (maxMoves - distance[dest]));
            ans += min(between, x + y);
        }

        return ans;
    }
};