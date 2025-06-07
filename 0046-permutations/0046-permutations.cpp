class Solution {
public:

    void solve(vector<int>& nums,vector<vector<int>> &ans,int index,vector<int> temp){

        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<nums.size(); i++){
            swap(nums[index],nums[i]);
            temp.push_back(nums[index]);
            solve(nums,ans,index+1,temp);
            temp.pop_back();
            swap(nums[index],nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,0,temp);
        return ans;

    }
};