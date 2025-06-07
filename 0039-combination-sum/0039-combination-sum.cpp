class Solution {
public:

    void solve(vector<int>& candidates, int target,int idx,vector<vector<int>> &ans,vector<int> temp){

        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx == candidates.size() || target < 0) return;


        // include
        temp.push_back(candidates[idx]);
        solve(candidates,target-candidates[idx],idx,ans,temp);
        temp.pop_back();

        solve(candidates,target,idx+1,ans,temp);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,0,ans,temp);
        return ans;
    }
};