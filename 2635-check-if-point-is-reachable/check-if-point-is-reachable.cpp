class Solution {
public:
    bool isReachable(int x, int y) {
        return (__gcd(x, y) & (__gcd(x, y) - 1)) == 0;
    }
};



