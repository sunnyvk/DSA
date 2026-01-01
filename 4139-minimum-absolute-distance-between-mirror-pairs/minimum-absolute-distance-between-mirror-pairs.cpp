class Solution {
public:
int reverse(int x){
    int res=0;
    while(x){
      res=res*10+x%10;
      x/=10;
    }
    return res;
}
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> lastOcc;
        lastOcc[reverse(nums[0])]=0;
        int res=INT_MAX;
        for(int j=1;j<nums.size();j++){
           if(lastOcc.count(nums[j])){
            res=min(res,j-lastOcc[nums[j]]);
           }
           lastOcc[reverse(nums[j])]=j;
        }
        return (res==INT_MAX) ? -1:res;
    }
};