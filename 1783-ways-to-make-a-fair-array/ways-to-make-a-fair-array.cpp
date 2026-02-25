class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        int osum=0,esum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i%2==0) esum+=nums[i];
            else osum+=nums[i];
        }
         for(int i=0;i<n;i++){
          if(i%2==0) esum-=nums[i];
          else osum-=nums[i];

          if(esum==osum) cnt++;
          if(i%2==0) osum+=nums[i];
          else esum+=nums[i];
        }
return cnt;
    }
};