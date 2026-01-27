class Solution {
public:
    using T=pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjN=it.first;
                int edW=it.second;
                if(dis+edW<dist[adjN]){
                    dist[adjN]=dis+edW;
                    pq.push({dis+edW,adjN});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
             if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
       return ans;
    }
};