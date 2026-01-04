class Solution {
public:
    using ll = long long;
    using i128 = __int128_t;
    long long minimumTime(vector<int>& d, vector<int>& r, ll time = 0) {
        ll low = 0, high = max(100LL, (d[0] + d[1]) * 1LL * max(r[0], r[1]));

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll x1 = mid - mid / r[0]; // drone 1 vacancies
            ll x2 = mid - mid / r[1]; // drone 2 vacancies
            ll x3 = mid - (mid / r[0] + mid/r[1] - mid/lcm(r[0], r[1])); // overlapping time
            if (x1 >= d[0] and x2 >= d[1] and x1 + x2 - x3 >= d[0] + d[1]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};