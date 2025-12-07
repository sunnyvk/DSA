class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int cnt=0;
          unordered_map<int, int> tuples;
  for (auto a : nums)
    for (auto b : nums) ++tuples[a & b];
  for (auto a : nums)
    for (auto t : tuples)
      if ((t.first & a) == 0) cnt += t.second;
  return cnt;
    }
};