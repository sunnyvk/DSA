class Solution {
public:

    bool isPalindrome(int n) {
        string s = "";

        while (n > 0) {
            s += char('0' + (n % 2));
            n /= 2;
        }

        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    vector<int> minOperations(vector<int>& nums) {

        vector<int> pal;

        for (int x = 1; x <= 10000; x++) {
            if (isPalindrome(x)) {
                pal.push_back(x);
            }
        }

        vector<int> ans;

       for (int n : nums) {

    auto it = lower_bound(pal.begin(), pal.end(), n);

    int best = INT_MAX;

    if (it != pal.end()) {
        best = min(best, abs(n - *it));
    }

    if (it != pal.begin()) {
        --it;
        best = min(best, abs(n - *it));
    }

    ans.push_back(best);
}

        return ans;
    }
};