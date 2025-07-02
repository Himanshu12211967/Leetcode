class Solution {
public:

    int solve(int idx,int k,vector<int> &cookies,vector<int> &child){

        if(idx == cookies.size()){
            int maxi = 0;
            for(auto total : child){
                maxi = max(maxi,total);
            }
            return maxi;
        }

        int ans = INT_MAX;

        for(int i=0; i<k; i++){
            child[i] += cookies[idx];
            ans = min(ans,solve(idx+1,k,cookies,child));
            child[i] -= cookies[idx];
        }

        return ans;

    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> child(k,0);
        return solve(0,k,cookies,child);
    }
};