class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>> &dp){

        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(nums1[i] == nums2[j]){
            return dp[i][j] = 1 + solve(nums1,nums2,i-1,j-1,dp);
        }
        else{
            return dp[i][j] =  max(solve(nums1,nums2,i-1,j,dp),solve(nums1,nums2,i,j-1,dp));
        }

    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));

        // for(int i=nums1.size()-1; i>=0; i--){
        //     for(int j=nums2.size()-1; j>=0; j--){
        //         if(nums1[i] == nums2[j]){
        //             dp[i][j] = 1;
        //             if(i+1 < nums1.size() && j+1 < nums2.size()) dp[i][j] += dp[i+1][j+1];
        //         }
        //         else{
        //             int opt1 = (i+1 < nums1.size()) ? dp[i+1][j] : 0;
        //             int opt2 = (j+1 < nums2.size()) ? dp[i][j+1] : 0;;
        //             dp[i][j] = max(opt1,opt2);
        //         }
        //     }
        // }

        return solve(nums1,nums2,nums1.size()-1,nums2.size()-1,dp);

    }
};