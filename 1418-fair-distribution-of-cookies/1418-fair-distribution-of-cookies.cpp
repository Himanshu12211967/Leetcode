class Solution {
public:

    int solve(int idx,int k,vector<int> &cookies,vector<int> &count){

        if(idx == cookies.size()){
            int maxi = 0;
            for(auto val : count){
                maxi = max(maxi,val);
            }
            return maxi;
        }

        int ans = INT_MAX;
        
        for(int i=0; i<k; i++){
            count[i] += cookies[idx];
            ans = min(ans,solve(idx+1,k,cookies,count));
            count[i] -= cookies[idx];
        }

        return ans;

    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> count(k,0);
        return solve(0,k,cookies,count);
    }
};