class Solution {
public:
void build(int i,int low,int high,vector<int>&seg,vector<int>&arr)
    {
        if(low>high)return;
        if(low==high)
        {
            seg[i]=arr[low];
            return;
        }
        int mid=(low+high)>>1;
        build(2*i+1,low,mid,seg,arr);
        build(2*i+2,mid+1,high,seg,arr);
        seg[i]=seg[2*i+1]&seg[2*i+2];
    }
    int query(int i,int low,int high,int l,int r,vector<int>&seg)
    {
        if(low>=l && high<=r)return seg[i];
        if(low>r || high<l || low>high)return -1;
        int mid=(low+high)>>1;
        int left=query(2*i+1,low,mid,l,r,seg);
        int right=query(2*i+2,mid+1,high,l,r,seg);
        return left & right;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>seg(4*n+4);
        build(0,0,n-1,seg,nums);
        long long ans=0;
        int l=0;
        for(int i=0;i<n;++i)
        {
            int val=query(0,0,n-1,i,n-1,seg);
            if(val>k)continue;
            int pos=-1;
            int l=i,r=n-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(query(0,0,n-1,i,mid,seg)<=k)
                {
                    pos=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            l=i,r=n-1;
            int pos1=-1;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(query(0,0,n-1,i,mid,seg)>=k)
                {
                    pos1=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(pos1!=-1 && pos!=-1)
            {
                ans+=1LL*(pos1-pos+1);
            }
        }
        return ans;
    }
};