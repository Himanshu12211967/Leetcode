class Solution {
public:

    bool canJump(vector<int>& nums) {
        
        int max_we_can_Reach = 0;

        for(int i=0; i<nums.size(); i++){

            if(max_we_can_Reach < i) return false;
            max_we_can_Reach = max(max_we_can_Reach,nums[i]+i);

        }

        return true;
    }
};