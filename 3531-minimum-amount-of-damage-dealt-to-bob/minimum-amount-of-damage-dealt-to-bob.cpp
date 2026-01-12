class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n=health.size();
        vector<int> time(n,0);
        for(int i=0;i<n;i++){
            time[i]=(health[i]%power)==0 ? (health[i]/power):(health[i]/power+1);
        }
        vector<double> damage_ps(n,0);
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n;i++){
            damage_ps[i]=(double)(damage[i]/(time[i] * 1.0));
            pq.push({damage_ps[i],i});
        }
        int total=accumulate(damage.begin(),damage.end(),0);
        long long ans=0;
        while(!pq.empty()){
            int ind=pq.top().second;
            int dmg=pq.top().first;
            pq.pop();
            ans=ans+1LL*total *(time[ind]);
            total=total-damage[ind];
        }
        return ans;
    }
};