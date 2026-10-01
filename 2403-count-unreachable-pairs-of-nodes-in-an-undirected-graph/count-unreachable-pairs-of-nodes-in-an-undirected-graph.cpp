class Solution {
public:
void dfs(vector<vector<int>>& adj,int node,int& cnt,vector<bool> &vis){
    if(vis[node]) return;
    cnt++;
    vis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it])   dfs(adj,it,cnt,vis);
    }
    
}
    long long countPairs(int n, vector<vector<int>>& edges) {
   vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
      long long ans = 1LL * n * (n - 1) / 2;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                  int cnt = 0;
                dfs(adj,i,cnt,vis);
                ans -= 1LL * cnt * (cnt - 1) / 2;
            }
        } 
        return (long long)ans;
    }
};