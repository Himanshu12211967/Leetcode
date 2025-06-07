class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_SubArray = INT_MIN;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            if(sum < 0) sum = 0;
            sum += nums[i];
            max_SubArray = max(max_SubArray,sum);
        }

        return max_SubArray;
    }
};