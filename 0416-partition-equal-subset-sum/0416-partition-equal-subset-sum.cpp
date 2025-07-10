class Solution {
public:

    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1,false));
        
        for(int i=0; i<=arr.size(); i++){
            dp[i][0] = true;
        }
        
        for(int i=arr.size()-1; i>=0; i--){
            
            for(int j=0; j<=sum; j++){
                
                bool pick = false;
                
                if(j-arr[i] >= 0){
                    pick = dp[i+1][j-arr[i]];
                }
                
                bool notpick = dp[i+1][j];
                
                dp[i][j] = notpick || pick;
            }
        }
        
        return dp[0][sum];
    }

    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % 2 != 0) return false;
        int target = sum / 2;

        return isSubsetSum(nums,target);
    }
};