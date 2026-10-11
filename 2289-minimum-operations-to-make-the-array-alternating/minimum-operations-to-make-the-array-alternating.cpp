class Solution {
    int freq[100005][2];
public:
    int minimumOperations(vector<int>& nums) {
        memset(freq, 0, sizeof(freq));
        int n=nums.size(), i, j, k, ans=0;
        for(i = 0; i < n; i++) {
			freq[nums[i]][i&1]++;
		}
        for(i = 1, j=k=0; i <= 100000; i++) {
		   // Add the maximum frequency of odd indexes to maximum frequency even indexes 
		   //and vice versa, it will give us how many elements we don't need to change. 
            ans = max(ans, max(freq[i][0] + k, freq[i][1] + j));
            j = max(j, freq[i][0]);
            k = max(k, freq[i][1]);
        }
        return n - ans;
    }
};