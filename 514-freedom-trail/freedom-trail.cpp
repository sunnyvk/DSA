class Solution {
public:
    int countSteps(int ringIndex, int i, int n) {
        int dist       = abs(i - ringIndex);
        int wrapAround =  n - dist;
        
        return min(dist, wrapAround);
    }
    
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length(); 
        
        vector<vector<int>> t(n+1, vector<int>(m+1, INT_MAX));
        //t[ringIndex][keyIndex] = minimum number of steps to get key[keyIndex] when the ring[ringIndex] is aligned with the "12:00" position.
        
        //If 
        for(int ringIndex = 0; ringIndex < n; ringIndex++) {
            t[ringIndex][m] = 0; //base case when all key chars are done (we reached index n)
        }
    
        for(int keyIndex = m-1; keyIndex >= 0; keyIndex--) {
            for(int ringIndex = 0; ringIndex < n; ringIndex++) {
                
                 int result = INT_MAX;
                 for (int i = 0; i < ring.length(); i++) {
                    if (ring[i] == key[keyIndex]) {
                        int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 +
                                                    t[i][keyIndex + 1];
                        result = min(result, totalSteps);
                    }
                }
                t[ringIndex][keyIndex] = result;
            }
        }
        return t[0][0];
    }
};