class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id,
                            int k) {
                                auto comp=[](pair<int,int> &a,pair<int,int> &b){
                                    if(a.first==b.first) return a.second > b.second;
                                      return a.first < b.first;
                                };
        priority_queue<pair<int, int>, vector<pair<int, int>>,decltype(comp)> pq(comp);
        unordered_set<string> pos, neg;
        for (auto s : positive_feedback)
            pos.insert(s);
        for (auto s : negative_feedback)
            neg.insert(s);

        for (int i = 0; i < report.size(); i++) {
            int l = 0, r = 0, points = 0;
            string s = report[i]+' ';
            while (r < s.size()) {
                if (s[r]==' ') {
                    string t = s.substr(l, r - l);
                    if (pos.find(t) != pos.end())
                        points += 3;
                    else if (neg.find(t) != neg.end())
                        points -= 1;
                    l = r + 1;
                }
                r++;
            }
            pq.push({points,student_id[i]});
        }
        vector<int> ans;
        while(pq.size()> 0 && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};