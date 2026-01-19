class Solution {
public:
  vector<int> buildLPS(const string& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0;
        for (int i = 1; i < m; ) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
    vector<pair<int,int>> findAll(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        vector<pair<int,int>> ans;
        if (m > n) return ans;

        vector<int> lps = buildLPS(pattern);
        int i = 0, j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++; j++;
            }
            if (j == m) {
                ans.push_back({i - j, i - 1});
                j = lps[j - 1];
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
    return ans;
    }
    int countCells(vector<vector<char>>& grid, string pattern) {
        int n=grid.size();
        int m=grid[0].size();
        int sz=pattern.size();
        string h="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                h+=grid[i][j];
            }
        }
        string v="";
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                v+=grid[i][j];
            }
        }
         vector<pair<int,int>> horiInterval = findAll(h,pattern);
        vector<pair<int,int>> verInterval = findAll(v,pattern);
        vector<int> hh(h.length(),0);
        vector<int> vv(v.length(),0);
        for(int i=0;i<horiInterval.size();i++){
            int start=horiInterval[i].first;
            int end=horiInterval[i].second;
            if(start<hh.size()){
                hh[start]++;
            }
            if(end+1<hh.size()){
                hh[end+1]--;
            }
        }
           for(int i=0;i<verInterval.size();i++){
            int start=verInterval[i].first;
            int end=verInterval[i].second;
            if(start<vv.size()){
                vv[start]++;
            }
            if(end+1<vv.size()){
                vv[end+1]--;
            }
        }
         for(int i=1;i<hh.size();i++){
            hh[i]+=hh[i-1];
            vv[i]+=vv[i-1];
        }
        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(hh[r*m+c] && vv[c*n+r]){
                    ans++;
                }
            }
        }
        return ans;

    }
};