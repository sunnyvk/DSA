class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      int i=0,j=0,pointer1=0,pointer2=0;
      while(i<word1.size() && j<word2.size()){
        char c1=word1[i][pointer1];
        char c2=word2[j][pointer2];
        if(c1!=c2) return false;
        pointer1++;
        pointer2++;
        if(pointer1==word1[i].size()){
            pointer1=0;
            i++;
        }
          if(pointer2==word2[j].size()){
            pointer2=0;
            j++;
        }
      }
      return i==word1.size() && j==word2.size();
    }
};