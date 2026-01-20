class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int t=0;t<=60;t++){
            long long val=(long long)num1-(long long)t*num2;
            if(val<0) continue;
            if(__builtin_popcountll(val)<=t && t<=val){
                return t;
            }
        }
        return -1;
    }
};