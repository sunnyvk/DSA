class Solution {
public:
    const int MOD = 1e9 + 7;
    unordered_map<string, int> mp;
    vector<long long> dp;

    Solution() {
        mp["**"] = 15; // 11–19 and 21–26
        mp["*0"] = 2;  // 10, 20
        mp["*1"] = 2;
        mp["*2"] = 2;
        mp["*3"] = 2;
        mp["*4"] = 2;
        mp["*5"] = 2;
        mp["*6"] = 2;
        mp["*7"] = 1;  
        mp["*8"] = 1;
        mp["*9"] = 1;
        mp["1*"] = 9;  // 11–19
        mp["2*"] = 6;  // 21–26
    }

    int numDecodings(string s) {
        dp.assign(s.size(), -1);  // initialize memo
        return (int)solve(0, s);
    }

private:
    long long solve(int p, string &s) {
        int n = s.size();

        if (p == n) return 1;
        if (s[p] == '0') return 0;

        if (dp[p] != -1) return dp[p];   // 🔥 memo hit

        long long ways = 0;

        // 🔹 Single character
        if (s[p] == '*')
            ways = 9LL * solve(p + 1, s);
        else
            ways = solve(p + 1, s);

        ways %= MOD;

        // 🔹 Two characters
        if (p < n - 1) {
            string s2 = s.substr(p, 2);

            if (s2.find('*') != string::npos) {
                ways = (ways + 1LL * mp[s2] * solve(p + 2, s)) % MOD;
            }
            else {
                if (s[p] == '1' || (s[p] == '2' && s[p + 1] <= '6')) {
                    ways = (ways + solve(p + 2, s)) % MOD;
                }
            }
        }

        return dp[p] = ways;  // 🔥 store result
    }
};

