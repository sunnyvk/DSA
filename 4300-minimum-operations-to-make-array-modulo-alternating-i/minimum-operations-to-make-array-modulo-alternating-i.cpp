class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int n=nums.size();
        int  ans=INT_MAX;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i==j)continue;
                int cost=0;
                for(int l=0;l<nums.size();l++){
                    int rem=nums[l]%k;
                    if(l%2==0){
                        cost+=min((i-rem+k)%k,(rem-i+k)%k);
                    }
                    else{
                         cost+=min((j-rem+k)%k,(rem-j+k)%k);
                    }   
                }
                ans=min(ans,cost);
            }
        }
       return ans;
    }
};