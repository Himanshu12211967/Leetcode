class Solution {
public:

    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size()+1,0);
        
        for(int idx=nums.size()-1; idx>=0; idx--){

            int ch1 = nums[idx];
            if(idx+2 < nums.size()) ch1 += dp[idx+2];
            
            int ch2 = dp[idx+1];
            dp[idx] = max(ch1,ch2);

        }

        return dp[0];

    }
};