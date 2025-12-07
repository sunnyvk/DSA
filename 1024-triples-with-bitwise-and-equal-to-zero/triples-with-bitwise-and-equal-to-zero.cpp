class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int tuples[1<<16]={};
        int cnt=0;
        for(auto a:nums){
            for(auto b:nums){
             tuples[a&b]++;
            }
        }
         for(auto a:nums){
            for(int i=0;i<1<<16;i++){
                if((i&a)==0) cnt+=tuples[i];
            }
         }
         return cnt;
    }
};