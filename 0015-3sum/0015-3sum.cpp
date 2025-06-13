class Solution {
public:

    void solve(vector<int>& nums,set<vector<int>> &s){

        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            set<int> st;
            for(int j=i+1; j<nums.size(); j++){
                int comp = target - nums[j];
                if(st.find(comp) != st.end()){
                    vector<int> temp = {nums[i],nums[j],comp};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                st.insert(nums[j]);
            }
        }

    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> s;
        solve(nums,s);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};