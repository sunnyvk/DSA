

class DisJointSet {
public:
    vector<int>rank,parent,size;

    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUPar(int node){        
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ultP_u= findUPar(u);   
        int ultP_v= findUPar(v);
        if(ultP_u == ultP_v) return;

        if(rank[ultP_u] < rank[ultP_v]){
            parent[ultP_u]=ultP_v;
        }
        else if(rank[ultP_v] < rank[ultP_u]){
            parent[ultP_v]=ultP_u;
        }
        else{
            parent[ultP_v]=ultP_u;
            rank[ultP_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ultP_u=findUPar(u);
        int ultP_v=findUPar(v);

        if(ultP_u == ultP_v) return;

        if(size[ultP_u] < size[ultP_v]){
            parent[ultP_u]=ultP_v;
            size[ultP_v]+=size[ultP_u];
        }
        else{
            parent[ultP_v]=ultP_u;
            size[ultP_u]+=size[ultP_v];
        }
    }

};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisJointSet ds(n);
        int cntExtras=0;
        for(auto &it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){  
                cntExtras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cntC++;
            }
        }

        int ans=cntC-1;

        if(cntExtras < ans ){
            return -1;
        }

        return ans;
    }
};