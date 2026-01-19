class Solution {
public:
    bool isPal(long long n) {
        long long r, sum = 0, temp;
        temp = n;
        while (n > 0) {
            r = n % 10;
            sum = (sum * 10) + r;
            n = n / 10;
        }
        return temp == sum;
    }

    long long calculateCost(vector<int>& nums, long long r) {
        long long cost = 0;
        for (int n : nums) {
            cost += llabs(n - r);
        }
        return cost;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long middle = 0;
        if (n == 1) {
    if (isPal(nums[0])) return 0;

    long long x = nums[0];
    long long low = x - 1, high = x + 1;
    while (true) {
        if (low >= 0 && isPal(low)) return x - low;
        if (isPal(high)) return high - x;
        low--;
        high++;
    }
}


        if (n % 2 != 0) {
            middle = nums[(n) / 2];
        } else {
            middle = (nums[(n /2)-1] + nums[n / 2]) / 2;
        }
        long long ans=1e15;
        if(isPal(middle)) {
            ans=calculateCost(nums,middle);
        }
        
        long long low=middle-1;
        long long high=middle+1;
        long long left=-1,right=-1;
        while(left==-1 || right==-1) {
            if(left==-1 && low>=0 && isPal(low)) {
                left=low;
            }
            if(right==-1 && isPal(high)) {
                right=high;
            }
            low--;
            high++;
        }

        return min(ans,min(calculateCost(nums,right),calculateCost(nums,left)));
    }
};