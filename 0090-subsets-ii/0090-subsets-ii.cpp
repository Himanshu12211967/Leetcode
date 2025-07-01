class Solution {
public:

    void solve(vector<int> &nums, int idx, vector<int> temp, vector<vector<int>> &ans){

        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        if(idx > 0 && temp.size() > 0 && nums[idx] == temp[temp.size()-1]){
            temp.push_back(nums[idx]);
            solve(nums,idx+1,temp,ans);
            temp.pop_back();
        }
        else{
            temp.push_back(nums[idx]);
            solve(nums,idx+1,temp,ans);
            temp.pop_back();
            solve(nums,idx+1,temp,ans);
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,temp,ans);
        return ans;
    }
};