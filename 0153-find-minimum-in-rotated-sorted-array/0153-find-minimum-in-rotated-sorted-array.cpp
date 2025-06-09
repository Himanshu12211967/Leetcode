class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        if(nums.size() >= 2){
            if(nums[0] < nums[1] && nums[0] < nums[nums.size()-1]) return nums[0];
            if(nums[nums.size()-1] < nums[nums.size()-2] && nums[0] > nums[nums.size()-1]) return nums[nums.size()-1];
        }

        int low = 1,high = nums.size()-2;

        while(low <= high){

            if(nums[low-1] > nums[low] && nums[low] < nums[low+1]) return nums[low];
            if(nums[high-1] > nums[high] && nums[high] < nums[high+1]) return nums[high];
            ++low;
            --high;
        }

        return -1;  

    }
};