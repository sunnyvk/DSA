class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mx = nums[n - 1];
        vector<bool> present(mx+1,false);
        for(auto it:nums){
            present[it]=true;
        }
                vector<int> best(mx + 1, -1);

        for(int d=1;d<=mx;d++){
            if(!present[d]) continue;
            for(int i=d;i<=mx;i+=d){
               if(best[i]==-1){
                best[i]=d;
               }
            }
        }
        long long ans=0;
        for(auto it:nums){
            ans+=best[it];
        }
        return ans;
    }
};