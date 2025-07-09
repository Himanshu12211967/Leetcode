class Solution {
public:

    int tabulation(string &word1, string &word2){

        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0));

        int n = word1.length();
        int m = word2.length();

        for (int i = 0; i <= n; i++) dp[i][m] = n - i;  // Remaining deletions
        for (int j = 0; j <= m; j++) dp[n][j] = m - j;  // Remaining insertions

        for(int i=word1.length()-1; i>=0; i--){
            for(int j=word2.length()-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int opt1 = 1 + dp[i+1][j+1];
                    int opt2 = 1 + dp[i+1][j];
                    int opt3 = 1 + dp[i][j+1];
                    dp[i][j] = min({opt1,opt2,opt3});
                }
            }
        }

        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        return tabulation(word1,word2);
    }
};