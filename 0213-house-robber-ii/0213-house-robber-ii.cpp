class Solution {
public:

    int solve(vector<int> &nums, int st,int end,vector<int> &dp){

        if(st > end) return 0;
        if(dp[st] != -1) return dp[st];

        int include = nums[st] + solve(nums,st+2,end,dp);
        int exclude = solve(nums,st+1,end,dp);
        return dp[st] = max(include,exclude);
    }

    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        
        vector<int> dp(nums.size()+1,-1);
        int firstway = solve(nums,0,nums.size()-2,dp);
        vector<int> dp2(nums.size()+1,-1);
        int secondway = solve(nums,1,nums.size()-1,dp2);
        return max(firstway,secondway);
    }

};