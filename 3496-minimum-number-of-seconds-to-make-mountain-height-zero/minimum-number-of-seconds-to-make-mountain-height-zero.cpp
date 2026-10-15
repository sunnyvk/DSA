class Solution {
public:
    bool canFinish(long long t, int mountainHeight,
                   vector<int>& workerTimes) {
        long long total = 0;

        for (int w : workerTimes) {
            long long q = t / w;

            long long x =
                (sqrtl(1.0L + 8.0L * q) - 1.0L) / 2.0L;

            total += x;

            if (total >= mountainHeight) {
                return true;
            }
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight,
                                 vector<int>& workerTimes) {
        long long low = 1;

        long long w = *min_element(
            workerTimes.begin(), workerTimes.end()
        );

        long long high =
            w * mountainHeight * (mountainHeight + 1LL) / 2;

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canFinish(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};