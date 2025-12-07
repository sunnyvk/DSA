class Solution {
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int n = array.size();
        int r = n - 1;
        int result = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }


public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n+1,0);
        vector<vector<int>> array(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        auto comp = [&](auto& vec1, auto& vec2) {
            return vec1[0] <vec2[0];
        } ;
        sort(array.begin(), array.end(), comp);
        for(int i=n-1;i>=0;i--){
             int next = getNextIndex(array, i + 1, array[i][1]);
        int taken = array[i][2] + dp[next];
        int nottaken = dp[i + 1];
        dp[i]= max(taken,nottaken);
        }

        return dp[0];
    }
};