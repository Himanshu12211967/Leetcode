class Solution {
public:

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans = 0;
        int lastmin = -1;
        int lastmax = -1;
        int lastinvalid = -1;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] < minK || nums[i] > maxK) lastinvalid = i;
            if(nums[i] == minK) lastmin = i;
            if(nums[i] == maxK) lastmax = i;

            int validstart = min(lastmin,lastmax);
            if(lastinvalid < validstart){
                ans += validstart - lastinvalid;
            }
        }

        return ans;
    }
};