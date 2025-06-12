class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> m;

        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i];
            if(m.find(comp) != m.end()) return {i,m[comp]};
            m[nums[i]] = i;
        }

        return {};

    }
};