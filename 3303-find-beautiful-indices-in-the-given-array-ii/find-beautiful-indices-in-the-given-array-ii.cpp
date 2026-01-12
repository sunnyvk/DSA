class Solution {
public:
    // -------- KMP LPS computation --------
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // -------- KMP search: returns 0-based indices --------
    vector<int> search(string pat, string txt) {
        int N = txt.size();
        int M = pat.size();

        vector<int> lps(M);
        computeLPS(pat, lps);

        vector<int> result;
        int i = 0, j = 0;

        while (i < N) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == M) {
                result.push_back(i - j); // 0-based index
                j = lps[j - 1];
            } 
            else if (i < N && txt[i] != pat[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return result;
    }

    // -------- Main function --------
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> first  = search(a, s); // indices of a
        vector<int> second = search(b, s); // indices of b
  vector<int> ans;
        int j = 0;

        for (int i = 0; i < first.size(); i++) {
            // move j so that B[j] is close to A[i]
            while (j < second.size() && second[j] < first[i] - k) {
                j++;
            }

            // check if this B[j] is within range
            if (j < second.size() && abs(first[i] - second[j]) <= k) {
                ans.push_back(first[i]);
            }
        }
        return ans;
    }
};
