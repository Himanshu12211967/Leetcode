class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long count = 0;
        int left = 0;
        int right = 0;
        long long sum = 0;

        while(right < nums.size()){

            sum += nums[right];

            int len = right-left+1;

            while(sum*len >= k){
                sum -= nums[left++];
                len = right - left + 1;
            }

            count = count + right - left + 1;
            right++;
        }

        return count;
    }
};