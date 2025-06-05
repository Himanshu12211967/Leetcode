class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        
        int pro = 1;
        int zero = 0;
        vector<int> ans(nums.size(),0);

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }
            else
            pro *= nums[i];
        }

        if(zero >= 2) return ans;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) ans[i] = pro;
            else if(zero == 1)
            ans[i] = 0;
            else ans[i] = pro/nums[i];
        }

        return ans;

    }
};