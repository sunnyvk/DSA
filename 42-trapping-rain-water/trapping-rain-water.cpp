class Solution {
public:
    int trap(vector<int>& height) {
        int lmax,rmax,total=0;
        int left=0,right=height.size()-1;
        while(left<=right){
            if(height[left]<=height[right]){
                    if(lmax>height[left]){
                        total+=lmax-height[left];
                    }else{
                        lmax=height[left];
                    }
                    left++;
            }else{
                if(rmax>height[right]){
                    total+=rmax-height[right];
                }else{
                    rmax=height[right];
                }
                right--;
            }
        }
        return total;
    }
};