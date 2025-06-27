class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int pivot = -1;

        for(int i=nums.size()-1; i>=1; i--){
            if(nums[i] > nums[i-1]){
                pivot = i-1;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        sort(nums.begin()+pivot+1,nums.end());

        for(int i=pivot+1; i<nums.size(); i++){
            if(nums[i] > nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        sort(nums.begin()+pivot+1,nums.end());

    }
};