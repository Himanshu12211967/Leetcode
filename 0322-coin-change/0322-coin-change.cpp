class Solution {
public:

    int solve(vector<int>& coins, int amount,int idx,vector<vector<int>> &dp){

        if(amount == 0) return 0;
        if(idx == coins.size() || amount < 0) return INT_MAX;
        if(dp[amount][idx] != -1) return dp[amount][idx];

        int include = INT_MAX,exclude = INT_MAX;

        int rec = solve(coins,amount-coins[idx],idx,dp);
        if(rec != INT_MAX) include = 1 + rec;

        exclude = solve(coins,amount,idx+1,dp);

        return dp[amount][idx] = min(include,exclude);

    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        int ans = solve(coins,amount,0,dp);
        return (ans == INT_MAX) ? -1 : ans;

    }
};