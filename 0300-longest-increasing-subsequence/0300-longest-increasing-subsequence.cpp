class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int LIS = 1;

        for(int i=1; i<nums.size(); i++){
            int count = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    count = max(count,dp[j]+1);
                }
            }
            dp[i] = count;
            LIS = max(LIS,count);
        }

        return LIS;
    }
};