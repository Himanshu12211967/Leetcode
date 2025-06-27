class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long subarrays = 0;
        int left = 0;
        int right = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int count = 0;

        while(right < nums.size()){

            if(nums[right] == maxi) count++;

            while(count >= k){
                if(nums[left] == maxi) count--;
                left++;
            }

            subarrays += left;
            right++;
        }


        return subarrays;
    }
};