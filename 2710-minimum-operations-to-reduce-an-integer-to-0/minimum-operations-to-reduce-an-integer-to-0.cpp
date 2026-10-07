class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        while(n>0){
            if(n%2==0){
                n/=2;
            }else{
                ans++;
                if(n==1) n=0;
                if(n%4==3){
                    n++;
                }else{
                    n--;
                }
            }
        }
        return ans;
    }
};