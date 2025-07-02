class Solution {
public:

    void solve(int idx, vector<vector<int>> &ans,vector<int>& nums,vector<int> temp){

        if(idx == nums.size()){
            if(temp.size() >= 2)
            ans.push_back(temp);
            return;
        }

        if(idx > 0 && temp.size() > 0 && temp[temp.size()-1] == nums[idx]){
            temp.push_back(nums[idx]);
            solve(idx+1,ans,nums,temp);
            temp.pop_back();
        }
        else{
            if(temp.empty() || temp.size() > 0 && temp.back() <= nums[idx]){
                temp.push_back(nums[idx]);
                solve(idx+1,ans,nums,temp);
                temp.pop_back();
            }
            solve(idx+1,ans,nums,temp);
        }

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,ans,nums,temp);
        return ans;
    }
};