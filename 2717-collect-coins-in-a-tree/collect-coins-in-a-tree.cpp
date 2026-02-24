class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(coins[i]==0 && deg[i]==1) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(deg[u]==0) continue;
            deg[u]=0;
            for(auto v:adj[u]){
                if(deg[v]>0){
                    deg[v]--;
                    if(deg[v]==1 && coins[v]==0)
                    q.push(v);
                }
            }
        }
        for(int s=0;s<2;s++){
           for(int i=0;i<n;i++){
             if(deg[i]==1) q.push(i);
           }
            while(!q.empty()){
               int u=q.front();
                q.pop();
                if(deg[u]==0) continue;
                deg[u]=0; 
                for(auto v:adj[u]){
                    if(deg[v]>0) deg[v]--;
                } 
            }
        }
        int cnt=0;
        for(auto e:edges){
            if(deg[e[0]]>0 && deg[e[1]]>0 ) cnt++;
        }
        return cnt*2;
    }
};