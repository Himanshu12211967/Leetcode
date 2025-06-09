class Solution {
public:

    int leftindex = -1;
    int rightindex = -1;

    void leftsearchRange(vector<int> &nums,int target){

        int st = 0,end = nums.size()-1;

        while(st <= end){
            int mid = st+(end-st)/2;
            if(nums[mid] == target){
                leftindex = mid;
                end = mid-1;
            }
            else if(nums[mid] > target) end = mid-1;
            else st = mid+1;
        }
    }

    void rightsearchRange(vector<int> &nums,int target){

        int st = 0,end = nums.size()-1;
        
        while(st <= end){
            int mid = st+(end-st)/2;
            if(nums[mid] == target){
                rightindex = mid;
                st = mid+1;
            }
            else if(nums[mid] > target) end = mid-1;
            else st = mid+1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans;
        leftsearchRange(nums,target);
        rightsearchRange(nums,target);
        ans = {leftindex,rightindex};
        return ans;
        
    }
};