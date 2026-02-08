class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD=1e9+7;
        vector<pair<int,int>> engineers;
        for(int i=0;i<n;i++){
            engineers.push_back({efficiency[i],speed[i]});
        }
        sort(engineers.rbegin(),engineers.rend());
        long long speedSum=0;
        long long best=0;
         priority_queue<int, vector<int>, greater<int>> minHeap;
          for (int i = 0; i < n; i++) {
            int currEfficiency = engineers[i].first;
            int currSpeed = engineers[i].second;
             minHeap.push(currSpeed);
            speedSum += currSpeed;

            // Keep only top k speeds
            if (minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }

            // Calculate performance
            long long performance = speedSum * currEfficiency;
            best = max(best, performance);
          }
           return best % MOD;
    }
};