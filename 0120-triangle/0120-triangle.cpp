class Solution {
public:

    int solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp){

        if(i == triangle.size()-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int sum = triangle[i][j];

        int way1 = sum + solve(triangle,i+1,j,dp);
        int way2 = sum + solve(triangle,i+1,j+1,dp);

        return dp[i][j] = min(way1,way2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> dp(triangle.size()+1,vector<int>(202,-1));
        return solve(triangle,0,0,dp);
    }
};