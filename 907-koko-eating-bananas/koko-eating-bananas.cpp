class Solution {
public:
   int findMax(vector<int>& piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
   }
    double calculateTotalHours(vector<int>& piles,int hourly){
        double totalH=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalH +=ceil((double)piles[i]/(double)hourly);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high){
           int mid=(low+high)/2;
            double totalH=calculateTotalHours(piles,mid);
            if(totalH<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};