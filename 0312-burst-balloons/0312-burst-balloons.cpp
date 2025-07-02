class Solution {
public:

    int solve(vector<int> &balloons,int left,int right,vector<vector<int>> &dp){

        if(left+1 == right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int ans = INT_MIN;

        for(int i=left+1; i<right; i++){
            int coins = balloons[left]*balloons[i]*balloons[right];
            coins += solve(balloons,left,i,dp) + solve(balloons,i,right,dp);
            ans = max(ans,coins);
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {

        vector<int> balloons;
        balloons.push_back(1);
        for(auto val : nums){
            balloons.push_back(val);
        }
        balloons.push_back(1);
        vector<vector<int>> dp(balloons.size()+1,vector<int>(balloons.size()+1,-1));

        return solve(balloons,0,balloons.size()-1,dp);
    }
};