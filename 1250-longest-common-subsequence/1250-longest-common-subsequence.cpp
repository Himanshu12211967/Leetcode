class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));

        for(int i=0; i<text1.length(); i++){
            for(int j=0; j<text2.length(); j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1;
                    if(i-1 >= 0 && j-1 >= 0)
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    int left = 0,right = 0;
                    if(i-1 >= 0) left = dp[i-1][j];
                    if(j-1 >= 0) right = dp[i][j-1];
                    dp[i][j] = max(left,right);
                }
            }
        }

        return dp[text1.length()-1][text2.length()-1];
    }
};