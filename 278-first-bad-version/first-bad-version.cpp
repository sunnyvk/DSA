// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low=1,high=n,minBadVersion;
        while(low<=high){
            long long mid=(low+high)/2;
            if(isBadVersion(mid)==1){
                    minBadVersion=mid;
                    high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return minBadVersion;
    }
};