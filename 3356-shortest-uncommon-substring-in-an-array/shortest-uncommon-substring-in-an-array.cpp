class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n=arr.size();
        vector<string> ans(n,"");
       for(int i=0;i<n;i++){
            string best ="";
            for(int len=1;len<=arr[i].size();len++){
                for(int start=0;start+len<=arr[i].size();start++){
                    string sub=arr[i].substr(start,len);
                      bool found=false;
                    for(int j=0;j<n;j++){ 
                        if(i==j) continue;
                      
                        if(arr[j].find(sub)!=string::npos){
                            found=true;
                            break;
                        }
                    }
                    if(!found){
                    if(best == "" || sub<best){
                        best=sub;
                    }
                    }
                
                }
                if(best!=""){
                    ans[i]=best;
                    break;
                }
            }
       }
       return ans;
    }
};