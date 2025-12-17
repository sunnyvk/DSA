class Solution {
public:
typedef pair<int,int> P;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1 || n==0) return 0;
        queue<P> que;
        set<P> visited;
        for(int i=0;i<n;i++){
            int maskvalue=(1<<i);
            que.push({i,maskvalue});
            visited.insert({i,maskvalue});
        }
        int allVisitedState=(1<<n)-1;
        int path=0;
        while(!que.empty()){
            int size=que.size();
            path++;
            while(size--){
                P curr=que.front();
                que.pop();
                int currNode=curr.first;
                int currMask=curr.second;
                for(int &adj:graph[currNode]){
                    int nextMask=currMask|(1<<adj);
                    if(nextMask==allVisitedState) return path;
                    if(visited.find({adj,nextMask})==visited.end()){
                        visited.insert({adj,nextMask});
                         que.push({adj,nextMask});
                    }
                }

            }
        }
        return -1;
    }
};