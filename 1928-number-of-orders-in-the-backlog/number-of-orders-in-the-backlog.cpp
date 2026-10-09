class Solution {
public:
long long MOD=1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            sell;
        priority_queue<pair<int, int>, vector<pair<int, int>>> buy;
        for (auto it : orders) {
            int price = it[0];
            int amount = it[1];
            int type = it[2];
            if (type == 0) {
                while (!sell.empty() && amount > 0 &&
                       sell.top().first <= price) {
                    auto [sellPrice, sellAmount] = sell.top();
                    sell.pop();
                    int matched = min(amount, sellAmount);
                    amount -= matched;
                    sellAmount -= matched;
                    if (sellAmount > 0)
                        sell.push({sellPrice, sellAmount});
                }
                if (amount > 0) {
                    buy.push({price, amount});
                }
            } else {
                while (!buy.empty() && amount > 0 && buy.top().first >= price) {
                    auto [buyPrice, buyAmount] = buy.top();
                    buy.pop();
                    int matched = min(amount, buyAmount);
                    amount -= matched;
                    buyAmount -= matched;
                    if (buyAmount > 0)
                        buy.push({buyPrice, buyAmount});
                }
                if (amount > 0) {
                    sell.push({price, amount});
                }
            }
        }
          long long total = 0;
            while(!buy.empty()){
                total=(total+buy.top().second)%MOD;
                buy.pop();
            }
             while(!sell.empty()){
                total=(total+sell.top().second)%MOD;
                sell.pop();
            } 
           return (int)total;
    }
};