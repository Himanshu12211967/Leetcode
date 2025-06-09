class Solution {
public:

    int binarysearch(vector<int> &nums,int st,int end,int target){

        while(st <= end){
            int mid = st+(end-st)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid-1;
            else st = mid+1;
        }

        return -1;
    }

    int peakelement(vector<int> &nums){

        int st = 0,end = nums.size()-1;

        while(st < end){

            int mid = st+(end-st)/2;
            if(nums[mid] >= nums[0]) st = mid+1;
            else end = mid;
        }

        return st;
        
    }

    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            return -1;
        }
        
        int peak = peakelement(nums);
        cout<<peak;
        if(target >= nums[0] && target <= nums[peak-1]){
            return binarysearch(nums,0,peak-1,target);
        } 
        return binarysearch(nums,peak,nums.size()-1,target);

    }
};