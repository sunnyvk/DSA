class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c :s){
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        s="";
        while(!pq.empty()){
            s += string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return s;
    }
};