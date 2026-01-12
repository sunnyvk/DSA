class Solution {
public:
    bool isPossible(vector<int> &price, int minDist, int k)
    {
        int take = 1; 
        int lastCowPosition = price[0];
        for (int i = 1; i < price.size(); i++)
        {
            if (price[i] - lastCowPosition >= minDist)
            {
                take++;
                lastCowPosition = price[i];
                if (take >= k)
                    return true;
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
   int n = price.size();
        sort(price.begin(), price.end());
        int l = 1, h = price[n - 1] - price[0];
        int ans = 0;
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (isPossible(price, m, k))
            {
                ans = m;
                l = m + 1;
            }
            else
                h = m - 1;
        }
        return ans;
    }
};