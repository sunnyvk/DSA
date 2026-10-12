class Solution {
public:
 long long minimalKSum(vector<int>& nums, int k) {     
        set<int>s(nums.begin(),nums.end());
        long long ans = (long(k)*(long(k+1)))/2; 
        for(auto i:s){
            if(i<=k){ 
            ans+=k+1;
            ans-=i;
            k++;
          }
            else  
                break;
        }
        return ans;
    }
};