class Solution {
    typedef long long int ll;
    bool IsPossible (int len, const vector<int>& nums, const vector<ll>& prefix, const ll K, int n) {
        if(len == 0)
            return false;
        
        int i = 0;
        int j = len-1;
        
        while(j < n) {
            ll target_idx = (i+j) / 2;
            ll target     = nums[target_idx];
            
            
            ll operations_left  = 0;
            ll operations_right = 0;
            
            if(target_idx == 0) {
                operations_left = 0;
            } else {
                operations_left = abs(((target_idx - i) * target) - (prefix[target_idx-1] - (i > 0 ? prefix[i-1] : 0)));
            }
            
            operations_right    = abs(((j - target_idx) * target) - (prefix[j] - prefix[target_idx]));
          
            if(operations_right + operations_left <= K) {
                return true;
            }
            
            i++;
            j++;
            
        }
        
        return false;
    }
    
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        
        vector<ll> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) 
            prefix[i] = prefix[i-1] + nums[i];
        
        int min_score     = 1;
        int max_score     = n;
        int result_score  = 1;
        
        while (min_score <= max_score) {
            int mid = (min_score + max_score) / 2;
            
            if (IsPossible(mid, nums, prefix, k, n)) {
                result_score = mid;
                min_score = mid + 1;
            } else {
                max_score = mid - 1;
            }
        }
        
        return result_score;
    }
};