class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {
        
        int left = 0;
        int right = 0;
        int zero_so_far = 0;
        int max_len = 0;

        while(right < nums.size()){

            if(nums[right] == 0) zero_so_far++;

            while(zero_so_far > k){
                if(nums[left] == 0) zero_so_far--;
                left++;
            }

            max_len = max(max_len,right-left+1);
            right++;
        }

        return max_len;
    }
};