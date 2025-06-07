class Solution {
public:

    bool solve(string s1, string s2, string s3,int i,int j,int k,vector<vector<vector<int>>> &dp){

        if(k >= s3.length()) return true;
        if(dp[i][j][k] != -1) return dp[i][j][k];

        if(i < s1.length() && s1[i] == s3[k]){
            if(solve(s1,s2,s3,i+1,j,k+1,dp)) return true;
        }
        if(j < s2.length() && s2[j] == s3[k]){
            if(solve(s1,s2,s3,i,j+1,k+1,dp)) return true;
        }
        return dp[i][j][k] = false;

    }

    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.length()+s2.length() != s3.length()) return false;
        vector<vector<vector<int>>> dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length(),-1)));
        return solve(s1,s2,s3,0,0,0,dp);

    }
};