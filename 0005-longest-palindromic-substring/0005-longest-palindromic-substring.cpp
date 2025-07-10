class Solution {
public:

    string longestPalindrome(string s) {
        
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        int start = 0;
        int min_len = INT_MIN;

        for(int col=0; col<s.length(); col++){
            for(int row=0; row<=col; row++){
                if(row == col) dp[row][col] = 1;
                else if(s[row] == s[col] && (dp[row+1][col-1] == 1 || abs(col-row == 1))){
                    dp[row][col] = 1;
                }
                else dp[row][col] = 0;

                if(dp[row][col] == 1 && min_len < col-row+1){
                    min_len = col-row+1;
                    start = row;
                }
            }
        }

        if(min_len == INT_MIN) return "";
        string ans = s.substr(start,min_len);
        return ans;

    }
};