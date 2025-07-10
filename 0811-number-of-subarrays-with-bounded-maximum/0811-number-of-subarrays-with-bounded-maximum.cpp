class Solution {
public:

    int solve(vector<int>& nums, int bound){

        int count = 0,curr = 0;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] <= bound){
                curr++;
            }
            else{
                curr = 0;
            }
            count += curr;
        }

        return count;

    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return solve(nums,right) - solve(nums,left-1);
    }
};