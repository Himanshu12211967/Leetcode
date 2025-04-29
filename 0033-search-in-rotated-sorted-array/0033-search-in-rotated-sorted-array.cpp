class Solution {
public:

    int getpivot(vector<int> &nums){

        int st = 0;
        int end = nums.size()-1;

        while(st < end){
            int mid = st + (end-st)/2;
            if(nums[mid] >= nums[0]) st = mid+1;
            else end = mid;
        }

        return st;
    }

    int binarysearch(vector<int> &nums, int st, int end, int target){

        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) st = mid+1;
            else end = mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int key) {

        if(nums.size() == 1){
            if(nums[0] == key) return 0;
            return -1;
        }

        int pivot = getpivot(nums);
        cout<<pivot;
        if(key >= nums[0] && key <= nums[pivot-1]){
            return binarysearch(nums,0,pivot-1,key);
        }
        return binarysearch(nums,pivot,nums.size()-1,key);

    }
};