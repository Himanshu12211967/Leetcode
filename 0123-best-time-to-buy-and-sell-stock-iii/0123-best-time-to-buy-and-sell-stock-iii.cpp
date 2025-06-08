class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));

        for (int idx = n-1; idx >= 0; idx--) {
            for (int max_transaction = 0; max_transaction <= 2; max_transaction++) {
                for (int canwebuy = 0; canwebuy <= 1; canwebuy++) {
                    int ch1 = 0, ch2 = 0, ch3 = 0;
                    if (canwebuy == 1 && max_transaction != 0) {
                        ch1 = -prices[idx] + dp[idx+1][max_transaction-1][0];
                    }
                    else if (canwebuy == 0) {
                        ch2 = prices[idx] + dp[idx+1][max_transaction][1];
                    }
                    ch3 = dp[idx+1][max_transaction][canwebuy];

                    dp[idx][max_transaction][canwebuy] = max({ch1, ch2, ch3});
                }
            }
        }

        return dp[0][2][1];
    }
};
