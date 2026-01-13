class Solution {
public:
int solve(int i,vector<int>& nums,int k,unordered_map<int, int> &freq){
    int n=nums.size();
    if(i==n){
        return 1;
    }
    
    int result=solve(i+1,nums,k,freq);
    if(!freq[nums[i]-k] && !freq[nums[i]+k]){
        freq[nums[i]]++;
        result+=solve(i+1,nums,k,freq);
        freq[nums[i]]--;
    }
    return result;
}
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
       return solve(0,nums,k,freq)-1;
    }
};