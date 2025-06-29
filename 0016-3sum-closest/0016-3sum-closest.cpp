class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans = 0;
        int min_dif = INT_MAX;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){

            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;

            while(left < right){

                int sum = nums[left] + nums[right] + nums[i];
                if(sum == target) return sum;
                else if(sum > target){
                    while(right > left && nums[right] == nums[right-1]) {right--;}
                    right--;
                }
                else{
                    while(right > left && nums[left] == nums[left+1]) {left++;}
                    left++;
                }

                if(abs(target-sum) < min_dif){
                    ans = sum;
                    min_dif = abs(target-sum);
                }
            }

        }

        return ans;
    }
};