class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));

        for(int idx=prices.size()-1; idx>=0; --idx){
            for(int canwebuy=0; canwebuy <= 1; ++canwebuy){
                int ch1 = 0,ch2 = 0,ch3 = 0;
                if(canwebuy == 1){
                    ch1 = -prices[idx]+dp[idx+1][0];
                }
                else{
                    ch2 = prices[idx]+dp[idx+1][1];
                }
                ch3 = dp[idx+1][canwebuy];
                dp[idx][canwebuy] = max({ch1,ch2,ch3});
            }
        }

        return dp[0][1];
    }
};