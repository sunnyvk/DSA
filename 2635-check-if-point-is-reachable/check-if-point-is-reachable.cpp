class Solution {
public:
    bool isReachable(int x, int y) {
        while (x > 0 && y > 0) {

            // 🎯 If we reached start point
            if (x == 1 && y == 1) return true;

            // STEP 1: Remove powers of 2 (undo doubling)
            if (x % 2 == 0) {
                x /= 2;
                continue;
            }
            if (y % 2 == 0) {
                y /= 2;
                continue;
            }

            // STEP 2: Both odd → must undo subtraction
            if (x > y) {
                x = x - y;  // reverse of (x+y, y)
            } else {
                y = y - x;  // reverse of (x, x+y)
            }
        }

        return false; // we hit zero → impossible
    }
};
