class Solution {
public:

    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum = 0;
        int left = 0;
        int right = 0;
        map<int,int> mapp;
        int ans = 0;

        while(right < nums.size()){

            sum += nums[right];
            mapp[nums[right]]++;

            while(mapp[nums[right]] > 1 && left <= right){
                sum -= nums[left];
                mapp[nums[left]]--;
                left++;
            }

            ans = max(ans,sum);
            right++;
        }

        return ans;
    }
};