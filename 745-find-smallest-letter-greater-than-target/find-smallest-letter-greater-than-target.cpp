class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        char ans=letters[0];
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if((letters[mid]-'0')>(target-'0')){
                ans=letters[mid];
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};