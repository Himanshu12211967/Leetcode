class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        
        int st = 0,end = nums.size()-1;
        int ans = 0;

        while(st <= end){
            int mid = st+(end-st)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                ans = mid+1;
                st = mid+1;
            }
            else end = mid-1;
        }

        return ans;
    }
};