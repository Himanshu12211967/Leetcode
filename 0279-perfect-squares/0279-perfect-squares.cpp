class Solution {
public:

    int solve(int num,unordered_map<int,int> &dp){

        if(num < 0) return INT_MAX;
        if(num == 0) return 0;
        if(num == 1) return 1;
        if(dp.find(num) != dp.end()) return dp[num];

        int ans = INT_MAX;

        for(int i=1; i<=num/2; i++){
            int sqr = i*i;
            int rec = solve(num-sqr,dp);
            if(rec != INT_MAX){
                ans = min(ans,rec+1);
            }
        }

        return dp[num] = ans;
    }

    int numSquares(int n) {
        
        unordered_map<int,int> dp;
        return solve(n,dp);
    }
};