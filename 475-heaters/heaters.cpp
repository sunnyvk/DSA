class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int n = houses.size();
        int m = heaters.size();

        vector<int> dist(n, INT_MAX);

        // 1️⃣ Nearest heater on the RIGHT side
        int j = 0;
        for (int i = 0; i < n && j < m; ) {
            if (houses[i] <= heaters[j]) {
                dist[i] = heaters[j] - houses[i];
                i++;
            } else {
                j++;
            }
        }

        // 2️⃣ Nearest heater on the LEFT side
        j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; ) {
            if (houses[i] >= heaters[j]) {
                dist[i] = min(dist[i], houses[i] - heaters[j]);
                i--;
            } else {
                j--;
            }
        }

        // 3️⃣ Maximum of minimum distances
        return *max_element(dist.begin(), dist.end());
    }
};
