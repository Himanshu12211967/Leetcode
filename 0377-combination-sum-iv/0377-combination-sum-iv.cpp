class Solution {
public:

    int solve(vector<int>& nums, int target,map<int,int> &dp){

        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp.find(target) != dp.end()) return dp[target];

        int total = 0;

        for(int i=0; i<nums.size(); i++){
            total += solve(nums,target-nums[i],dp);
        }

        return dp[target] = total;
    }


    int combinationSum4(vector<int>& nums, int target) {
        map<int,int> dp;
        return solve(nums,target,dp);
    }
};