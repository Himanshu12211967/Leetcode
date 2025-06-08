class Solution {
public:

    int solve(vector<int>& prices,int idx,int max_transaction,int canwebuy,vector<vector<vector<int>>> &dp){

        if(idx == prices.size()) return 0;
        if(dp[idx][max_transaction][canwebuy] != -1) return dp[idx][max_transaction][canwebuy];

        int ch1 = 0,ch2 = 0,ch3 = 0;

        if(canwebuy == 1 && max_transaction != 0){
            ch1 = -prices[idx] + solve(prices,idx+1,max_transaction-1,0,dp);
        }
        else if(canwebuy == 0){
            ch2 = prices[idx] + solve(prices,idx+1,max_transaction,1,dp);
        }
        ch3 = solve(prices,idx+1,max_transaction,canwebuy,dp);

        return dp[idx][max_transaction][canwebuy] = max({ch1,ch2,ch3});

    }

    int solve2(vector<int>& prices){

        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(3,vector<int>(2,0)));

        for(int idx=prices.size()-1; idx>=0; idx--){
            for(int max_transaction=0; max_transaction<=2; max_transaction++){
                for(int canwebuy=0; canwebuy<=1; canwebuy++){
                    int ch1 = 0,ch2 = 0,ch3 = 0;

                    if(canwebuy == 1 && max_transaction != 0){
                        ch1 = -prices[idx] + dp[idx+1][max_transaction-1][0];
                    }
                    else if(canwebuy == 0){
                        ch2 = prices[idx] + dp[idx+1][max_transaction][1];
                    }
                    ch3 = dp[idx+1][max_transaction][canwebuy];

                    dp[idx][max_transaction][canwebuy] = max({ch1,ch2,ch3});
                }
            }
        }

        return dp[0][2][1];
    }

    int maxProfit(vector<int>& prices) {
        
        //vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
        //return solve(prices,0,2,1,dp);
        return solve2(prices);

    }
};