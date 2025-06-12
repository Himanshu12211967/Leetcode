class Solution {
public:

    void solve(int n,int k,vector<vector<int>> &ans,vector<int> temp){

        if(k == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=1; i<=n; i++){
            if(!temp.empty() && temp.back() >= i) continue;
            temp.push_back(i);
            solve(n,k-1,ans,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,k,ans,temp);
        return ans;
    }
};