class Solution {
public:
    int minimumPartition(string s, int k) {
        int i=0,j=0,count=0;
        while(j<s.length()){
            while(j<s.length() && stol(s.substr(i,j-i+1))<=k){
                j++;
            }
            count++;
            if(i==j) return -1;
            i=j;
        }
        return count;

    }
};