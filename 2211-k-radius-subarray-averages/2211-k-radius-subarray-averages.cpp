class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        long long int left_sum = 0;
        long long int right_sum = 0;
        vector<int> ans(nums.size(),-1);
        if(k >= nums.size()) return ans;

        for(int i=0; i<k; i++){
            left_sum += nums[i];
        }

        int count = 1;
        
        for(int i=k+1; i<nums.size() && count <= k; i++){
            right_sum += nums[i];
            count++;
        }

        int left_remove = 0;
        int right_remove = k+1;

        for(int i=k; i<nums.size()-k; i++){

            long long int sum = left_sum + right_sum + nums[i];
            ans[i] = sum/((2*k)+1);
            left_sum = left_sum - nums[left_remove++] + nums[i];

            if(right_remove < nums.size()){

                right_sum = right_sum - nums[right_remove++];

                if(i+k+1 < nums.size()){
                    right_sum += nums[i+k+1];
                }
            }
        }

        return ans;
    }
};