class Solution {
public:

    int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp){

        if(i == a.length() && j < b.length()) return b.length()-j;
        if(i < a.length() && j == b.length()) return a.length()-i;
        if(i == a.length() && j == b.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]){
            return dp[i][j] = solve(a,b,i+1,j+1,dp);
        }
        else{
            int ch1 = 1 + solve(a,b,i,j+1,dp);
            int ch2 = 1 + solve(a,b,i+1,j,dp);
            int ch3 = 1 + solve(a,b,i+1,j+1,dp);
            return dp[i][j] = min({ch1,ch2,ch3});
        }

    }

    int minDistance(string word1, string word2) {
        
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);

    }
};