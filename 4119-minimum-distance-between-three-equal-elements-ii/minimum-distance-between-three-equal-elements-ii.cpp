class Solution {
public:
    int minimumDistance(vector<int>& nums) {
          int n=nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int ans=-1;
        for(int i=2;i<vec.size();i++){
            if(vec[i].first==vec[i-1].first && vec[i].first==vec[i-2].first){
                int x=abs(vec[i].second-vec[i-1].second)+
                abs(vec[i].second-vec[i-2].second)+
                abs(vec[i-1].second-vec[i-2].second);
                if(ans==-1){
                    ans=x;
                }
                else ans=min(ans,x);
            }
        }
      return ans;
    }
};