class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& fr, vector<int>& to) {
	
            map<int,int> pos;
            
            for(int i = 0;i<nums.size();i++) pos[nums[i]]++; // Storing count of marble in map
            
            for(int i = 0;i<fr.size();i++){
                    int from = fr[i];
                    int too = to[i];
                    
                    if(pos.count(from)){
                            int marble  = pos[from]; // Find number of marble at prev position
                            pos.erase(from); // Erase from map
                            pos[too] = marble; // Insert at new position
                    }
            }
            
            vector<int> ans;
            
            for(auto [a,b] : pos)  ans.push_back(a); // Insert new positions to answer
            
            return ans;
        
    }
};