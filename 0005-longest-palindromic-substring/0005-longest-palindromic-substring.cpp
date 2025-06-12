class Solution {
public:

    string longestPalindrome(string s) {

        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        string lps = "";
        int max_len = 0;
        int start_index = 0;

        for(int col=0; col<s.length(); ++col){
            for(int row=0; row<=col; ++row){
                if(row == col) dp[row][col] = true;
                else if(s[row] == s[col] && (col-row == 1 || dp[row+1][col-1] == true)) dp[row][col] = true;
                else dp[row][col] = false;

                //updating the string index and length
                if(dp[row][col] == true && max_len < col-row+1){
                    max_len = col-row+1;
                    start_index = row;
                }
                
            }
        }

        return s.substr(start_index,max_len);
    }
};