class Solution {
public:

    int solve(vector<int>& nums, int target, int idx, int sum){

        if(idx == nums.size() && target == sum) return 1;
        if(idx == nums.size()) return 0;
        
        return solve(nums,target,idx+1,sum+nums[idx]) + solve(nums,target,idx+1,sum-nums[idx]);
    }

    int tabulation(vector<int>& nums, int target, int idx, int sum, map<pair<int,int>,int> &dp){

        if(idx == nums.size() && target == sum) return 1;
        if(idx == nums.size()) return 0;
        if(dp.find({idx,sum}) != dp.end()) return dp[{idx,sum}];
        
        int opt1 = tabulation(nums,target,idx+1,sum+nums[idx],dp);
        int opt2 = tabulation(nums,target,idx+1,sum-nums[idx],dp);
        return dp[{idx,sum}] = opt1 + opt2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        map<pair<int,int>,int> dp;
        return tabulation(nums,target,0,0,dp);

    }
};